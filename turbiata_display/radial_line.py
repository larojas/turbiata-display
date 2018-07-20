#
# This is a helper program to assist in creating a lookup table for a
# semicircular gauge. The gauge has a inner and outer radius, and when
# empty, a thin outline can be seen.
# 
# The program reads a png with the outline, and successively fills
# thin polygons thar represent the steps in filling up the semicircle.
#

import argparse
import cv2
import math
import numpy as np
import time

# Only slightly hacky: this program, when ran the first time, generates
# output to stdout with a file either in python or C++, depending on the
# arguments. The python file (if named radial_diffs.py) is then
# conditionally read if you run the program again, and it renders the
# resulting image for verification. Once verified, you know that
# the C++ file will work correctly. 
try:
  import radial_diffs
  diffs = radial_diffs.diffs
except ImportError:
  diffs = []

BLACK = (0, 0, 0)
RED = (0, 0, 255)
WHITE = (255, 255, 255)
ORIGIN = (63, 59)
RADIUS_OUTER = 57
RADIUS_INNER = 41
STEPS = 100
PERIOD = 1

def compute_diff(img1, img2):
  diff_list = []
  for row in range(len(img1)):
    start_diff = None
    for col in range(len(img1[0])):
      if not (img1[row, col] == img2[row, col]).all():
        if start_diff is None:
          start_diff = col
          if not diff_list:
            diff_list.append(row)
      elif start_diff is not None:
        diff_list.append((start_diff, col - start_diff))
        start_diff = None
        break
    if start_diff is not None:
      # diff spanned till end of row
      diff_list.append((start_diff, len(img1[0]) - start_diff))
  return diff_list

def get_line_coords(n, radius):
  """Compute coordinates for n+1 lines of length radius, starting at the origin
     going clockwise from 9 o'clock to 3 o'clock.
     
     Returns: an array with 100 tuples of the form (x,y)
  """
  a=[0]*(n+1)
  step_rad = math.pi / n
  angle = 0
  for i in range(n+1):
    a[i] = (int(radius * math.cos(angle)), int(radius * math.sin(angle)))
    angle += step_rad
  return a

def draw_step(a, b, step, img):
  points = np.array([shift(b[step - 1]), shift(a[step - 1]),
                     shift(a[step]), shift(b[step])])
  cv2.fillConvexPoly(img, points, RED)

def shift(point):
  return (ORIGIN[0] - point[0], ORIGIN[1] - point[1])

def apply_mask(dest, mask, transparent_color):
  for i in range(len(dest)):
    for j in range(len(dest[0])):
      if not (mask[i,j] == transparent_color).all():
        dest[i,j] = mask[i,j]
      pass

def white_like(img):
  rows = len(img)
  cols = len(img[0])
  img2 = np.zeros((rows, cols, 3), np.uint8)
  for i in range(rows):
    for j in range(cols):
      img2[i,j] = WHITE

def clean_img(img):
  cols = len(img[0])
  for row in range(len(img)):
      done_left = False
      done_right = False
      for col in range(cols):
        if not done_left:
          if (img[row, col] == BLACK).all():
            done_left = True
          else:
            img[row, col] = WHITE
        if not done_right:
          if (img[row, cols - col - 1] == BLACK).all():
            done_right = True
          else:
            img[row, cols - col - 1] = WHITE

def apply_diff(img, diff):
  if not diff: return
  row = diff[0]
  for i in range(1, len(diff)):
    start, length = diff[i]
    cv2.line(img, (start, row), (start + length - 1, row), RED)
    row += 1

def output_header(type):
  if type == 'py':
    print "diffs = ["
  else:
    print "namespace SemiGaugeDiff {"
    print "const uint8_t END = ~(uint8_t)0;"

def output_footer(type):
  if type == 'py':
    print "]"
  else:
    print "const uint8_t* const diffs[] PROGMEM = {"
    for i in range(1, STEPS + 1):
      print "diffs_%d%s " % (i, "," if i < STEPS else "")
    print "};"
    print "} // namespace SemiGaugeDiff"

def output_line(line, num, type):
  if type == 'py':
    print line, ","
  else:
    print 'const uint8_t diffs_%d[] PROGMEM = {' % num,
    if line:
      print "%d" % line[0],
      for i in range(1, len(line)):
        print ",%d,%d" % (line[i][0], line[i][1]),
      print ', END };'
    else:
      print 'END };'
    
def main():
  parser = argparse.ArgumentParser(description='Generate lines.')
  parser.add_argument('--output', choices=('py', 'h'), default='py')
  parser.add_argument('--imgfile', default='SemicircularGauge_mono.png')
  args = parser.parse_args()

  img = cv2.imread(args.imgfile)
  bg = np.copy(img)
  if (diffs):
    fast_img = np.copy(bg) # will be drawn using previously computed diffs
    cv2.imshow("vroom vroom", fast_img)
  else:
    cv2.imshow("vroom", img)
    a = get_line_coords(STEPS, RADIUS_OUTER)
    b = get_line_coords(STEPS, RADIUS_INNER)
    output_header(args.output)
  cv2.waitKey(0)
  for i in range(1, STEPS + 1):
    if diffs:
      apply_diff(fast_img, diffs[i-1])
      cv2.imshow("vroom vroom", fast_img)
    else:
      old_img = np.copy(img)
      draw_step(a, b, i, img)
      apply_mask(img, bg, WHITE)
      clean_img(img)
      output_line(compute_diff(old_img, img), i, args.output)
      cv2.imshow("vroom", img)
    cv2.waitKey(PERIOD)
  if not diffs:
    output_footer(args.output)
  cv2.waitKey(0)
  cv2.destroyAllWindows()

if __name__ == "__main__":
  main()
