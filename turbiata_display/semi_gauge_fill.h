namespace SemiGaugeDiff {
const uint8_t END = ~(uint8_t)0;

const uint8_t diffs_1[] PROGMEM = { 58 ,8,15 , END };
const uint8_t diffs_2[] PROGMEM = { 56 ,8,8 ,8,15 , END };
const uint8_t diffs_3[] PROGMEM = { 54 ,8,4 ,8,12 ,16,7 , END };
const uint8_t diffs_4[] PROGMEM = { 52 ,8,4 ,8,12 ,12,12 ,20,3 , END };
const uint8_t diffs_5[] PROGMEM = { 51 ,8,4 ,12,8 ,20,4 , END };
const uint8_t diffs_6[] PROGMEM = { 49 ,9,2 ,8,8 ,12,9 ,20,4 , END };
const uint8_t diffs_7[] PROGMEM = { 47 ,9,1 ,9,5 ,11,7 ,16,6 ,21,3 , END };
const uint8_t diffs_8[] PROGMEM = { 45 ,10,1 ,9,6 ,10,9 ,14,9 ,18,7 ,22,2 , END };
const uint8_t diffs_9[] PROGMEM = { 44 ,10,1 ,11,4 ,15,4 ,19,4 ,23,2 , END };
const uint8_t diffs_10[] PROGMEM = { 42 ,10,1 ,10,4 ,11,7 ,15,6 ,19,5 ,23,2 , END };
const uint8_t diffs_11[] PROGMEM = { 40 ,11,1 ,11,3 ,11,6 ,14,5 ,18,4 ,21,3 ,24,1 , END };
const uint8_t diffs_12[] PROGMEM = { 39 ,11,2 ,12,4 ,14,5 ,17,4 ,19,5 ,22,4 ,24,2 , END };
const uint8_t diffs_13[] PROGMEM = { 37 ,12,1 ,12,3 ,13,5 ,16,4 ,19,4 ,21,4 ,24,2 , END };
const uint8_t diffs_14[] PROGMEM = { 35 ,13,1 ,13,3 ,13,5 ,15,5 ,18,4 ,20,4 ,23,3 ,25,2 , END };
const uint8_t diffs_15[] PROGMEM = { 34 ,14,1 ,14,3 ,16,3 ,18,3 ,20,3 ,22,3 ,24,3 ,26,2 , END };
const uint8_t diffs_16[] PROGMEM = { 33 ,14,3 ,15,4 ,17,4 ,19,3 ,21,3 ,23,3 ,25,3 ,27,1 , END };
const uint8_t diffs_17[] PROGMEM = { 31 ,15,2 ,15,3 ,17,3 ,19,3 ,21,2 ,22,3 ,24,2 ,26,2 ,28,1 , END };
const uint8_t diffs_18[] PROGMEM = { 30 ,16,2 ,17,2 ,18,3 ,20,3 ,22,2 ,23,3 ,25,2 ,26,3 ,28,1 , END };
const uint8_t diffs_19[] PROGMEM = { 28 ,17,2 ,17,3 ,18,4 ,19,5 ,21,4 ,23,4 ,24,4 ,26,4 ,27,3 ,29,1 , END };
const uint8_t diffs_20[] PROGMEM = { 27 ,18,2 ,19,2 ,20,3 ,22,2 ,24,1 ,25,2 ,27,1 ,28,2 ,30,1 , END };
const uint8_t diffs_21[] PROGMEM = { 26 ,19,2 ,20,2 ,21,3 ,23,2 ,24,2 ,25,3 ,27,2 ,28,3 ,30,2 , END };
const uint8_t diffs_22[] PROGMEM = { 24 ,20,2 ,19,5 ,21,4 ,22,4 ,24,3 ,25,3 ,26,4 ,28,3 ,29,3 ,31,2 , END };
const uint8_t diffs_23[] PROGMEM = { 23 ,21,2 ,22,3 ,24,2 ,25,2 ,26,2 ,27,2 ,28,3 ,30,2 ,31,2 ,32,2 , END };
const uint8_t diffs_24[] PROGMEM = { 21 ,23,1 ,22,3 ,23,3 ,25,2 ,26,3 ,27,3 ,28,3 ,29,3 ,31,2 ,32,2 ,33,1 , END };
const uint8_t diffs_25[] PROGMEM = { 20 ,23,2 ,24,2 ,25,2 ,26,2 ,27,2 ,29,1 ,30,1 ,31,1 ,32,1 ,33,1 ,34,1 , END };
const uint8_t diffs_26[] PROGMEM = { 19 ,24,2 ,25,2 ,26,2 ,27,2 ,28,2 ,29,2 ,30,1 ,31,1 ,32,1 ,33,1 ,34,1 , END };
const uint8_t diffs_27[] PROGMEM = { 18 ,26,2 ,26,3 ,27,2 ,28,2 ,29,2 ,30,2 ,31,2 ,31,3 ,32,2 ,33,2 ,34,2 ,35,2 , END };
const uint8_t diffs_28[] PROGMEM = { 17 ,27,2 ,28,2 ,29,1 ,29,2 ,30,2 ,31,2 ,32,2 ,33,2 ,34,1 ,34,2 ,35,2 ,36,2 , END };
const uint8_t diffs_29[] PROGMEM = { 15 ,29,2 ,28,3 ,29,3 ,30,3 ,30,3 ,31,3 ,32,3 ,33,3 ,34,2 ,35,2 ,35,3 ,36,2 ,37,2 , END };
const uint8_t diffs_30[] PROGMEM = { 14 ,30,2 ,31,1 ,31,2 ,32,2 ,33,1 ,33,2 ,34,2 ,35,2 ,36,1 ,36,2 ,37,2 ,38,1 ,38,2 , END };
const uint8_t diffs_31[] PROGMEM = { 13 ,32,1 ,32,1 ,32,2 ,33,2 ,34,1 ,34,2 ,35,1 ,36,1 ,37,1 ,37,1 ,38,1 ,39,1 ,39,1 , END };
const uint8_t diffs_32[] PROGMEM = { 12 ,33,2 ,33,2 ,33,3 ,34,3 ,35,2 ,35,3 ,36,2 ,36,3 ,37,3 ,38,2 ,38,3 ,39,3 ,40,2 ,40,2 , END };
const uint8_t diffs_33[] PROGMEM = { 11 ,35,1 ,35,1 ,35,2 ,36,2 ,37,1 ,37,2 ,38,1 ,38,2 ,39,2 ,40,1 ,40,2 ,41,2 ,42,1 ,42,2 , END };
const uint8_t diffs_34[] PROGMEM = { 11 ,36,2 ,36,2 ,37,2 ,38,1 ,38,2 ,39,1 ,39,2 ,40,2 ,41,1 ,41,2 ,42,1 ,43,1 ,43,1 , END };
const uint8_t diffs_35[] PROGMEM = { 10 ,37,3 ,38,2 ,38,3 ,39,2 ,39,3 ,40,2 ,40,3 ,41,2 ,42,2 ,42,2 ,43,2 ,43,2 ,44,2 ,44,1 , END };
const uint8_t diffs_36[] PROGMEM = { 9 ,39,2 ,40,1 ,40,2 ,41,1 ,41,2 ,42,1 ,42,2 ,43,1 ,43,2 ,44,1 ,44,2 ,45,1 ,45,2 ,46,1 , END };
const uint8_t diffs_37[] PROGMEM = { 8 ,41,1 ,41,2 ,41,2 ,42,2 ,42,2 ,43,1 ,43,2 ,44,1 ,44,2 ,45,1 ,45,1 ,46,1 ,46,1 ,47,1 , END };
const uint8_t diffs_38[] PROGMEM = { 7 ,42,2 ,42,2 ,43,2 ,43,2 ,44,1 ,44,2 ,44,2 ,45,2 ,45,2 ,46,1 ,46,2 ,46,2 ,47,1 ,47,2 ,48,1 , END };
const uint8_t diffs_39[] PROGMEM = { 7 ,44,1 ,44,2 ,45,1 ,45,2 ,45,2 ,46,1 ,46,2 ,47,1 ,47,2 ,47,2 ,48,1 ,48,2 ,48,2 ,49,2 , END };
const uint8_t diffs_40[] PROGMEM = { 6 ,45,2 ,45,3 ,46,2 ,46,2 ,47,2 ,47,2 ,47,2 ,48,2 ,48,2 ,49,1 ,49,1 ,49,2 ,50,1 ,50,1 ,51,1 , END };
const uint8_t diffs_41[] PROGMEM = { 6 ,47,2 ,48,2 ,48,2 ,48,2 ,49,1 ,49,2 ,49,2 ,50,1 ,50,1 ,50,2 ,50,2 ,51,1 ,51,1 ,51,2 ,52,1 , END };
const uint8_t diffs_42[] PROGMEM = { 5 ,49,1 ,49,2 ,50,1 ,50,1 ,50,1 ,50,2 ,51,1 ,51,1 ,51,1 ,51,2 ,52,1 ,52,1 ,52,1 ,52,2 ,53,1 , END };
const uint8_t diffs_43[] PROGMEM = { 5 ,50,2 ,51,2 ,51,2 ,51,2 ,51,2 ,52,2 ,52,2 ,52,2 ,52,2 ,53,2 ,53,2 ,53,2 ,53,2 ,54,2 ,54,2 , END };
const uint8_t diffs_44[] PROGMEM = { 4 ,53,1 ,52,2 ,53,1 ,53,2 ,53,2 ,53,2 ,54,1 ,54,1 ,54,2 ,54,2 ,55,1 ,55,1 ,55,1 ,55,2 ,56,1 ,56,1 , END };
const uint8_t diffs_45[] PROGMEM = { 4 ,54,2 ,54,2 ,54,2 ,55,2 ,55,2 ,55,2 ,55,2 ,55,2 ,56,1 ,56,1 ,56,1 ,56,2 ,56,2 ,57,1 ,57,1 , END };
const uint8_t diffs_46[] PROGMEM = { 4 ,56,1 ,56,1 ,56,1 ,57,1 ,57,1 ,57,1 ,57,1 ,57,1 ,57,1 ,57,1 ,57,1 ,58,1 ,58,1 ,58,1 ,58,1 , END };
const uint8_t diffs_47[] PROGMEM = { 4 ,57,2 ,57,2 ,57,2 ,58,2 ,58,2 ,58,2 ,58,2 ,58,2 ,58,2 ,58,2 ,58,2 ,59,2 ,59,2 ,59,2 ,59,2 , END };
const uint8_t diffs_48[] PROGMEM = { 4 ,59,2 ,59,2 ,59,2 ,60,1 ,60,1 ,60,1 ,60,1 ,60,2 ,60,2 ,60,2 ,60,2 ,61,1 ,61,1 ,61,1 ,61,1 , END };
const uint8_t diffs_49[] PROGMEM = { 4 ,61,2 ,61,2 ,61,2 ,61,2 ,61,2 ,61,2 ,61,2 ,62,1 ,62,1 ,62,1 ,62,1 ,62,1 ,62,1 ,62,1 ,62,1 , END };
const uint8_t diffs_50[] PROGMEM = { 4 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 ,63,1 , END };
const uint8_t diffs_51[] PROGMEM = { 4 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 ,64,1 , END };
const uint8_t diffs_52[] PROGMEM = { 4 ,65,2 ,65,2 ,65,2 ,65,2 ,65,2 ,65,2 ,65,2 ,65,2 ,65,1 ,65,1 ,65,1 ,65,1 ,65,1 ,65,1 ,65,1 , END };
const uint8_t diffs_53[] PROGMEM = { 4 ,67,2 ,67,2 ,67,2 ,67,2 ,67,1 ,67,1 ,67,1 ,67,1 ,66,2 ,66,2 ,66,2 ,66,2 ,66,1 ,66,1 ,66,1 , END };
const uint8_t diffs_54[] PROGMEM = { 4 ,69,2 ,69,2 ,69,2 ,69,2 ,68,2 ,68,2 ,68,2 ,68,2 ,68,2 ,68,2 ,68,2 ,68,2 ,67,2 ,67,2 ,67,2 , END };
const uint8_t diffs_55[] PROGMEM = { 4 ,71,1 ,71,1 ,71,1 ,71,1 ,70,1 ,70,1 ,70,1 ,70,1 ,70,1 ,70,1 ,70,1 ,70,1 ,69,1 ,69,1 ,69,1 , END };
const uint8_t diffs_56[] PROGMEM = { 4 ,72,2 ,72,2 ,72,2 ,72,1 ,71,2 ,71,2 ,71,2 ,71,2 ,71,1 ,71,1 ,71,1 ,71,1 ,70,2 ,70,1 ,70,1 ,70,1 , END };
const uint8_t diffs_57[] PROGMEM = { 5 ,74,2 ,74,1 ,73,2 ,73,2 ,73,2 ,73,1 ,73,1 ,72,2 ,72,2 ,72,1 ,72,1 ,72,1 ,71,2 ,71,1 ,71,1 , END };
const uint8_t diffs_58[] PROGMEM = { 5 ,76,2 ,75,3 ,75,2 ,75,2 ,75,2 ,74,3 ,74,2 ,74,2 ,74,2 ,73,3 ,73,2 ,73,2 ,73,2 ,72,3 ,72,2 , END };
const uint8_t diffs_59[] PROGMEM = { 6 ,78,1 ,77,1 ,77,1 ,77,1 ,77,1 ,76,1 ,76,1 ,76,1 ,76,1 ,75,1 ,75,1 ,75,1 ,75,1 ,74,1 ,74,1 , END };
const uint8_t diffs_60[] PROGMEM = { 6 ,79,2 ,78,2 ,78,2 ,78,2 ,78,1 ,77,2 ,77,2 ,77,2 ,77,1 ,76,2 ,76,2 ,76,1 ,76,1 ,75,2 ,75,1 , END };
const uint8_t diffs_61[] PROGMEM = { 6 ,81,1 ,80,3 ,80,2 ,80,2 ,79,2 ,79,2 ,79,2 ,79,1 ,78,2 ,78,1 ,78,1 ,77,2 ,77,1 ,77,1 ,76,1 , END };
const uint8_t diffs_62[] PROGMEM = { 7 ,83,1 ,82,2 ,82,1 ,81,2 ,81,2 ,81,1 ,80,2 ,80,2 ,79,2 ,79,2 ,79,1 ,78,2 ,78,2 ,77,2 ,77,2 , END };
const uint8_t diffs_63[] PROGMEM = { 7 ,84,1 ,84,2 ,83,2 ,83,2 ,83,1 ,82,2 ,82,2 ,82,1 ,81,2 ,81,1 ,80,2 ,80,2 ,80,1 ,79,2 ,79,1 , END };
const uint8_t diffs_64[] PROGMEM = { 8 ,86,1 ,85,3 ,85,2 ,84,3 ,84,2 ,84,2 ,83,2 ,83,2 ,82,2 ,82,2 ,82,1 ,81,2 ,81,1 ,80,2 ,80,1 , END };
const uint8_t diffs_65[] PROGMEM = { 10 ,87,2 ,87,1 ,86,2 ,86,1 ,85,2 ,85,1 ,84,2 ,84,1 ,83,2 ,83,1 ,82,2 ,82,1 ,81,2 , END };
const uint8_t diffs_66[] PROGMEM = { 10 ,89,2 ,88,2 ,88,2 ,87,2 ,87,2 ,86,2 ,86,2 ,85,2 ,85,1 ,84,2 ,84,1 ,83,2 ,83,1 ,82,2 , END };
const uint8_t diffs_67[] PROGMEM = { 11 ,90,2 ,90,2 ,89,2 ,89,1 ,88,2 ,88,1 ,87,2 ,86,2 ,86,1 ,85,2 ,85,1 ,84,1 ,84,1 ,83,1 , END };
const uint8_t diffs_68[] PROGMEM = { 12 ,92,1 ,91,2 ,90,2 ,90,1 ,89,2 ,89,1 ,88,2 ,87,2 ,87,1 ,86,2 ,85,2 ,85,1 ,84,2 , END };
const uint8_t diffs_69[] PROGMEM = { 12 ,93,1 ,93,2 ,92,3 ,91,3 ,91,2 ,90,3 ,90,2 ,89,3 ,88,3 ,88,2 ,87,3 ,86,3 ,86,2 ,85,3 , END };
const uint8_t diffs_70[] PROGMEM = { 14 ,95,1 ,94,2 ,93,2 ,93,1 ,92,2 ,92,1 ,91,1 ,90,1 ,90,1 ,89,1 ,88,1 ,88,1 ,87,1 , END };
const uint8_t diffs_71[] PROGMEM = { 14 ,96,1 ,96,1 ,95,2 ,94,2 ,94,1 ,93,2 ,92,2 ,91,2 ,91,1 ,90,2 ,89,2 ,89,1 ,88,2 ,88,1 , END };
const uint8_t diffs_72[] PROGMEM = { 15 ,97,1 ,97,2 ,96,3 ,95,3 ,95,3 ,94,3 ,93,3 ,92,3 ,92,2 ,91,2 ,90,3 ,90,2 ,89,2 ,89,1 , END };
const uint8_t diffs_73[] PROGMEM = { 17 ,99,1 ,98,2 ,98,1 ,97,2 ,96,2 ,95,2 ,94,2 ,93,2 ,93,1 ,92,2 ,91,2 ,90,2 ,90,1 , END };
const uint8_t diffs_74[] PROGMEM = { 18 ,100,1 ,99,3 ,99,2 ,98,2 ,97,2 ,96,2 ,95,3 ,94,3 ,94,2 ,93,2 ,92,2 ,91,2 ,91,1 , END };
const uint8_t diffs_75[] PROGMEM = { 19 ,102,1 ,101,2 ,100,2 ,99,2 ,98,2 ,98,1 ,97,1 ,96,1 ,95,1 ,94,1 ,93,1 ,92,1 , END };
const uint8_t diffs_76[] PROGMEM = { 20 ,103,1 ,102,2 ,101,2 ,100,2 ,99,2 ,98,2 ,97,2 ,96,1 ,95,1 ,94,1 ,93,1 ,92,1 , END };
const uint8_t diffs_77[] PROGMEM = { 22 ,103,2 ,102,3 ,101,3 ,100,3 ,99,2 ,97,3 ,96,3 ,95,3 ,94,3 ,93,2 ,93,1 , END };
const uint8_t diffs_78[] PROGMEM = { 23 ,105,1 ,104,2 ,103,2 ,101,3 ,100,2 ,99,2 ,98,2 ,97,2 ,95,3 ,94,2 ,94,1 , END };
const uint8_t diffs_79[] PROGMEM = { 24 ,106,1 ,105,3 ,104,4 ,102,4 ,101,4 ,100,3 ,99,3 ,98,3 ,96,3 ,95,3 ,95,1 , END };
const uint8_t diffs_80[] PROGMEM = { 26 ,108,1 ,106,3 ,105,2 ,103,3 ,102,2 ,101,2 ,99,3 ,98,2 ,96,3 ,96,1 , END };
const uint8_t diffs_81[] PROGMEM = { 28 ,107,3 ,106,2 ,104,3 ,103,2 ,102,2 ,100,2 ,99,1 ,97,2 , END };
const uint8_t diffs_82[] PROGMEM = { 29 ,108,3 ,107,4 ,105,4 ,104,4 ,102,4 ,100,5 ,99,4 ,97,4 ,97,3 , END };
const uint8_t diffs_83[] PROGMEM = { 31 ,109,3 ,108,2 ,106,3 ,105,2 ,103,3 ,101,3 ,100,2 ,98,3 ,98,1 , END };
const uint8_t diffs_84[] PROGMEM = { 32 ,110,2 ,109,3 ,107,3 ,106,2 ,104,2 ,102,3 ,101,2 ,99,2 , END };
const uint8_t diffs_85[] PROGMEM = { 33 ,112,1 ,110,3 ,108,5 ,106,5 ,105,4 ,103,4 ,101,4 ,99,4 ,99,2 , END };
const uint8_t diffs_86[] PROGMEM = { 35 ,113,1 ,111,3 ,109,3 ,107,3 ,105,3 ,103,3 ,101,3 ,100,2 , END };
const uint8_t diffs_87[] PROGMEM = { 37 ,112,3 ,110,4 ,108,4 ,106,3 ,104,3 ,102,2 ,101,1 , END };
const uint8_t diffs_88[] PROGMEM = { 38 ,114,1 ,112,4 ,109,5 ,107,4 ,104,5 ,102,4 ,101,2 , END };
const uint8_t diffs_89[] PROGMEM = { 40 ,114,2 ,111,4 ,109,4 ,106,4 ,103,5 ,101,4 ,102,1 , END };
const uint8_t diffs_90[] PROGMEM = { 41 ,115,1 ,113,4 ,110,6 ,108,5 ,105,5 ,103,3 ,102,1 , END };
const uint8_t diffs_91[] PROGMEM = { 43 ,116,1 ,113,4 ,110,6 ,106,6 ,103,5 ,102,2 , END };
const uint8_t diffs_92[] PROGMEM = { 45 ,116,1 ,112,5 ,108,5 ,104,5 ,102,3 , END };
const uint8_t diffs_93[] PROGMEM = { 46 ,117,1 ,113,5 ,109,8 ,105,8 ,103,6 ,103,2 , END };
const uint8_t diffs_94[] PROGMEM = { 48 ,117,1 ,113,5 ,109,7 ,105,6 ,103,3 , END };
const uint8_t diffs_95[] PROGMEM = { 50 ,116,3 ,111,8 ,106,10 ,103,5 , END };
const uint8_t diffs_96[] PROGMEM = { 52 ,116,3 ,108,8 ,103,5 , END };
const uint8_t diffs_97[] PROGMEM = { 53 ,116,3 ,108,11 ,104,12 ,104,4 , END };
const uint8_t diffs_98[] PROGMEM = { 55 ,116,3 ,108,11 ,104,8 , END };
const uint8_t diffs_99[] PROGMEM = { 57 ,112,7 ,104,15 , END };
const uint8_t diffs_100[] PROGMEM = { END };
const uint8_t* const diffs[] PROGMEM = {
diffs_1, 
diffs_2, 
diffs_3, 
diffs_4, 
diffs_5, 
diffs_6, 
diffs_7, 
diffs_8, 
diffs_9, 
diffs_10, 
diffs_11, 
diffs_12, 
diffs_13, 
diffs_14, 
diffs_15, 
diffs_16, 
diffs_17, 
diffs_18, 
diffs_19, 
diffs_20, 
diffs_21, 
diffs_22, 
diffs_23, 
diffs_24, 
diffs_25, 
diffs_26, 
diffs_27, 
diffs_28, 
diffs_29, 
diffs_30, 
diffs_31, 
diffs_32, 
diffs_33, 
diffs_34, 
diffs_35, 
diffs_36, 
diffs_37, 
diffs_38, 
diffs_39, 
diffs_40, 
diffs_41, 
diffs_42, 
diffs_43, 
diffs_44, 
diffs_45, 
diffs_46, 
diffs_47, 
diffs_48, 
diffs_49, 
diffs_50, 
diffs_51, 
diffs_52, 
diffs_53, 
diffs_54, 
diffs_55, 
diffs_56, 
diffs_57, 
diffs_58, 
diffs_59, 
diffs_60, 
diffs_61, 
diffs_62, 
diffs_63, 
diffs_64, 
diffs_65, 
diffs_66, 
diffs_67, 
diffs_68, 
diffs_69, 
diffs_70, 
diffs_71, 
diffs_72, 
diffs_73, 
diffs_74, 
diffs_75, 
diffs_76, 
diffs_77, 
diffs_78, 
diffs_79, 
diffs_80, 
diffs_81, 
diffs_82, 
diffs_83, 
diffs_84, 
diffs_85, 
diffs_86, 
diffs_87, 
diffs_88, 
diffs_89, 
diffs_90, 
diffs_91, 
diffs_92, 
diffs_93, 
diffs_94, 
diffs_95, 
diffs_96, 
diffs_97, 
diffs_98, 
diffs_99, 
diffs_100 
};
} // namespace SemiGaugeDiff
