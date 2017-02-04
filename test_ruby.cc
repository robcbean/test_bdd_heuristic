
typedef unsigned int uint32_t;



#include "mtrInt.h"
#include "cuddObj.hh"
#include "output.h"
#include "operations.h"

#include <vector>
#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

   





void timeOut(DdManager* _manager, void* _output){
    std::vector<BDD> output;
    Cudd mgr(0,0);
    print_output(1013,"Electronic Shopping","symmetry\tCUDD_REORDER_SIFT\t-1.0\t-1.0\t5349\t290.0	351.0	2.0	0.7800373317614634	0.3265532273965427	0.6896551724137931	55.86206896551724	62.42046068405384	55.86206896551724	0.7800373317614705	0.5737505315647994	0.5698005698005698	9.193103448275862	2.1782077383021017	9.0",mgr,output,false,NULL,true);
}


int main( int argc, char **argv )
{

  Cudd mgr(330,0);
  mgr.AutodynDisable();

  BDD x[1013];
  double t1,t2,t3,t4;
  
  std::string str_output;
  char buffer[100];
  std::string grown="";
  
  double minTerms=0;
  
  //Output nodes
  std::vector<BDD> output(2);
  std::vector<BDD> count_nodes_vector;
  std::vector<unsigned long> count_nodes;
  std::vector<unsigned long> count_id;

  //Set CUDD TimeOut
  Cudd_SetTimeLimit(mgr.getManager(),600000);
  Cudd_RegisterTimeoutHandler(mgr.getManager(),timeOut,&output);


  //Variables
  
      x[4]  = mgr.bddVar(35); //4
  
      x[2]  = mgr.bddVar(41); //2
  
      x[5]  = mgr.bddVar(27); //5
  
      x[8]  = mgr.bddVar(59); //8
  
      x[6]  = mgr.bddVar(28); //6
  
      x[9]  = mgr.bddVar(60); //9
  
      x[12]  = mgr.bddVar(0); //12
  
      x[10]  = mgr.bddVar(2); //10
  
      x[13]  = mgr.bddVar(1); //13
  
      x[51]  = mgr.bddVar(105); //51
  
      x[49]  = mgr.bddVar(71); //49
  
      x[53]  = mgr.bddVar(106); //53
  
      x[52]  = mgr.bddVar(104); //52
  
      x[55]  = mgr.bddVar(61); //55
  
      x[48]  = mgr.bddVar(70); //48
  
      x[57]  = mgr.bddVar(63); //57
  
      x[74]  = mgr.bddVar(42); //74
  
      x[73]  = mgr.bddVar(50); //73
  
      x[76]  = mgr.bddVar(88); //76
  
      x[78]  = mgr.bddVar(64); //78
  
      x[84]  = mgr.bddVar(72); //84
  
      x[47]  = mgr.bddVar(73); //47
  
      x[90]  = mgr.bddVar(76); //90
  
      x[89]  = mgr.bddVar(75); //89
  
      x[95]  = mgr.bddVar(82); //95
  
      x[93]  = mgr.bddVar(81); //93
  
      x[97]  = mgr.bddVar(85); //97
  
      x[99]  = mgr.bddVar(86); //99
  
      x[96]  = mgr.bddVar(83); //96
  
      x[98]  = mgr.bddVar(84); //98
  
      x[92]  = mgr.bddVar(80); //92
  
      x[1]  = mgr.bddVar(74); //1
  
      x[56]  = mgr.bddVar(62); //56
  
      x[75]  = mgr.bddVar(95); //75
  
      x[91]  = mgr.bddVar(69); //91
  
      x[114]  = mgr.bddVar(99); //114
  
      x[113]  = mgr.bddVar(100); //113
  
      x[116]  = mgr.bddVar(102); //116
  
      x[112]  = mgr.bddVar(116); //112
  
      x[180]  = mgr.bddVar(164); //180
  
      x[178]  = mgr.bddVar(117); //178
  
      x[182]  = mgr.bddVar(167); //182
  
      x[181]  = mgr.bddVar(165); //181
  
      x[183]  = mgr.bddVar(166); //183
  
      x[117]  = mgr.bddVar(103); //117
  
      x[207]  = mgr.bddVar(204); //207
  
      x[205]  = mgr.bddVar(119); //205
  
      x[209]  = mgr.bddVar(203); //209
  
      x[208]  = mgr.bddVar(205); //208
  
      x[204]  = mgr.bddVar(118); //204
  
      x[82]  = mgr.bddVar(47); //82
  
      x[81]  = mgr.bddVar(49); //81
  
      x[80]  = mgr.bddVar(51); //80
  
      x[83]  = mgr.bddVar(48); //83
  
      x[79]  = mgr.bddVar(52); //79
  
      x[101]  = mgr.bddVar(78); //101
  
      x[100]  = mgr.bddVar(77); //100
  
      x[60]  = mgr.bddVar(26); //60
  
      x[58]  = mgr.bddVar(36); //58
  
      x[61]  = mgr.bddVar(25); //61
  
      x[65]  = mgr.bddVar(29); //65
  
      x[63]  = mgr.bddVar(24); //63
  
      x[67]  = mgr.bddVar(33); //67
  
      x[69]  = mgr.bddVar(34); //69
  
      x[66]  = mgr.bddVar(30); //66
  
      x[68]  = mgr.bddVar(31); //68
  
      x[70]  = mgr.bddVar(32); //70
  
      x[72]  = mgr.bddVar(23); //72
  
      x[71]  = mgr.bddVar(22); //71
  
      x[123]  = mgr.bddVar(43); //123
  
      x[122]  = mgr.bddVar(46); //122
  
      x[121]  = mgr.bddVar(56); //121
  
      x[119]  = mgr.bddVar(87); //119
  
      x[124]  = mgr.bddVar(57); //124
  
      x[136]  = mgr.bddVar(107); //136
  
      x[134]  = mgr.bddVar(110); //134
  
      x[137]  = mgr.bddVar(109); //137
  
      x[138]  = mgr.bddVar(108); //138
  
      x[144]  = mgr.bddVar(125); //144
  
      x[142]  = mgr.bddVar(123); //142
  
      x[146]  = mgr.bddVar(127); //146
  
      x[145]  = mgr.bddVar(126); //145
  
      x[140]  = mgr.bddVar(112); //140
  
      x[139]  = mgr.bddVar(111); //139
  
      x[141]  = mgr.bddVar(113); //141
  
      x[133]  = mgr.bddVar(121); //133
  
      x[131]  = mgr.bddVar(115); //131
  
      x[151]  = mgr.bddVar(138); //151
  
      x[153]  = mgr.bddVar(139); //153
  
      x[155]  = mgr.bddVar(141); //155
  
      x[154]  = mgr.bddVar(140); //154
  
      x[118]  = mgr.bddVar(114); //118
  
      x[115]  = mgr.bddVar(101); //115
  
      x[102]  = mgr.bddVar(79); //102
  
      x[126]  = mgr.bddVar(124); //126
  
      x[125]  = mgr.bddVar(134); //125
  
      x[128]  = mgr.bddVar(129); //128
  
      x[130]  = mgr.bddVar(133); //130
  
      x[149]  = mgr.bddVar(136); //149
  
      x[147]  = mgr.bddVar(122); //147
  
      x[150]  = mgr.bddVar(137); //150
  
      x[127]  = mgr.bddVar(128); //127
  
      x[0]  = mgr.bddVar(162); //0
  
      x[104]  = mgr.bddVar(90); //104
  
      x[103]  = mgr.bddVar(98); //103
  
      x[106]  = mgr.bddVar(97); //106
  
      x[87]  = mgr.bddVar(66); //87
  
      x[85]  = mgr.bddVar(68); //85
  
      x[88]  = mgr.bddVar(67); //88
  
      x[77]  = mgr.bddVar(120); //77
  
      x[186]  = mgr.bddVar(131); //186
  
      x[185]  = mgr.bddVar(130); //185
  
      x[187]  = mgr.bddVar(135); //187
  
      x[159]  = mgr.bddVar(145); //159
  
      x[157]  = mgr.bddVar(143); //157
  
      x[161]  = mgr.bddVar(150); //161
  
      x[163]  = mgr.bddVar(152); //163
  
      x[165]  = mgr.bddVar(151); //165
  
      x[167]  = mgr.bddVar(153); //167
  
      x[160]  = mgr.bddVar(146); //160
  
      x[164]  = mgr.bddVar(148); //164
  
      x[162]  = mgr.bddVar(147); //162
  
      x[166]  = mgr.bddVar(149); //166
  
      x[171]  = mgr.bddVar(155); //171
  
      x[169]  = mgr.bddVar(154); //169
  
      x[173]  = mgr.bddVar(159); //173
  
      x[175]  = mgr.bddVar(161); //175
  
      x[177]  = mgr.bddVar(160); //177
  
      x[172]  = mgr.bddVar(156); //172
  
      x[176]  = mgr.bddVar(158); //176
  
      x[156]  = mgr.bddVar(142); //156
  
      x[174]  = mgr.bddVar(157); //174
  
      x[129]  = mgr.bddVar(132); //129
  
      x[105]  = mgr.bddVar(89); //105
  
      x[168]  = mgr.bddVar(144); //168
  
      x[215]  = mgr.bddVar(171); //215
  
      x[214]  = mgr.bddVar(170); //214
  
      x[212]  = mgr.bddVar(190); //212
  
      x[238]  = mgr.bddVar(175); //238
  
      x[237]  = mgr.bddVar(172); //237
  
      x[220]  = mgr.bddVar(209); //220
  
      x[219]  = mgr.bddVar(208); //219
  
      x[218]  = mgr.bddVar(206); //218
  
      x[223]  = mgr.bddVar(211); //223
  
      x[221]  = mgr.bddVar(210); //221
  
      x[225]  = mgr.bddVar(214); //225
  
      x[224]  = mgr.bddVar(212); //224
  
      x[226]  = mgr.bddVar(213); //226
  
      x[216]  = mgr.bddVar(195); //216
  
      x[227]  = mgr.bddVar(207); //227
  
      x[229]  = mgr.bddVar(215); //229
  
      x[231]  = mgr.bddVar(218); //231
  
      x[233]  = mgr.bddVar(219); //233
  
      x[230]  = mgr.bddVar(216); //230
  
      x[232]  = mgr.bddVar(217); //232
  
      x[239]  = mgr.bddVar(176); //239
  
      x[235]  = mgr.bddVar(169); //235
  
      x[234]  = mgr.bddVar(168); //234
  
      x[236]  = mgr.bddVar(174); //236
  
      x[211]  = mgr.bddVar(191); //211
  
      x[301]  = mgr.bddVar(255); //301
  
      x[300]  = mgr.bddVar(249); //300
  
      x[210]  = mgr.bddVar(163); //210
  
      x[307]  = mgr.bddVar(272); //307
  
      x[306]  = mgr.bddVar(271); //306
  
      x[305]  = mgr.bddVar(252); //305
  
      x[309]  = mgr.bddVar(277); //309
  
      x[308]  = mgr.bddVar(276); //308
  
      x[316]  = mgr.bddVar(278); //316
  
      x[314]  = mgr.bddVar(275); //314
  
      x[318]  = mgr.bddVar(281); //318
  
      x[317]  = mgr.bddVar(279); //317
  
      x[319]  = mgr.bddVar(280); //319
  
      x[302]  = mgr.bddVar(250); //302
  
      x[191]  = mgr.bddVar(192); //191
  
      x[190]  = mgr.bddVar(187); //190
  
      x[196]  = mgr.bddVar(197); //196
  
      x[194]  = mgr.bddVar(196); //194
  
      x[198]  = mgr.bddVar(199); //198
  
      x[197]  = mgr.bddVar(198); //197
  
      x[193]  = mgr.bddVar(188); //193
  
      x[188]  = mgr.bddVar(173); //188
  
      x[192]  = mgr.bddVar(186); //192
  
      x[200]  = mgr.bddVar(189); //200
  
      x[199]  = mgr.bddVar(193); //199
  
      x[54]  = mgr.bddVar(58); //54
  
      x[109]  = mgr.bddVar(92); //109
  
      x[107]  = mgr.bddVar(91); //107
  
      x[111]  = mgr.bddVar(94); //111
  
      x[110]  = mgr.bddVar(93); //110
  
      x[243]  = mgr.bddVar(177); //243
  
      x[241]  = mgr.bddVar(220); //241
  
      x[245]  = mgr.bddVar(183); //245
  
      x[247]  = mgr.bddVar(185); //247
  
      x[249]  = mgr.bddVar(179); //249
  
      x[251]  = mgr.bddVar(184); //251
  
      x[244]  = mgr.bddVar(180); //244
  
      x[248]  = mgr.bddVar(178); //248
  
      x[246]  = mgr.bddVar(181); //246
  
      x[250]  = mgr.bddVar(182); //250
  
      x[294]  = mgr.bddVar(268); //294
  
      x[292]  = mgr.bddVar(265); //292
  
      x[297]  = mgr.bddVar(273); //297
  
      x[296]  = mgr.bddVar(270); //296
  
      x[298]  = mgr.bddVar(274); //298
  
      x[295]  = mgr.bddVar(269); //295
  
      x[240]  = mgr.bddVar(221); //240
  
      x[311]  = mgr.bddVar(263); //311
  
      x[310]  = mgr.bddVar(261); //310
  
      x[313]  = mgr.bddVar(264); //313
  
      x[257]  = mgr.bddVar(226); //257
  
      x[255]  = mgr.bddVar(228); //255
  
      x[258]  = mgr.bddVar(227); //258
  
      x[264]  = mgr.bddVar(230); //264
  
      x[254]  = mgr.bddVar(229); //254
  
      x[252]  = mgr.bddVar(233); //252
  
      x[287]  = mgr.bddVar(256); //287
  
      x[285]  = mgr.bddVar(251); //285
  
      x[291]  = mgr.bddVar(260); //291
  
      x[290]  = mgr.bddVar(259); //290
  
      x[289]  = mgr.bddVar(258); //289
  
      x[288]  = mgr.bddVar(257); //288
  
      x[261]  = mgr.bddVar(235); //261
  
      x[259]  = mgr.bddVar(234); //259
  
      x[262]  = mgr.bddVar(236); //262
  
      x[263]  = mgr.bddVar(237); //263
  
      x[268]  = mgr.bddVar(239); //268
  
      x[267]  = mgr.bddVar(238); //267
  
      x[270]  = mgr.bddVar(242); //270
  
      x[277]  = mgr.bddVar(243); //277
  
      x[276]  = mgr.bddVar(240); //276
  
      x[266]  = mgr.bddVar(222); //266
  
      x[283]  = mgr.bddVar(224); //283
  
      x[278]  = mgr.bddVar(244); //278
  
      x[265]  = mgr.bddVar(232); //265
  
      x[273]  = mgr.bddVar(246); //273
  
      x[271]  = mgr.bddVar(245); //271
  
      x[275]  = mgr.bddVar(248); //275
  
      x[274]  = mgr.bddVar(247); //274
  
      x[284]  = mgr.bddVar(225); //284
  
      x[312]  = mgr.bddVar(262); //312
  
      x[281]  = mgr.bddVar(253); //281
  
      x[279]  = mgr.bddVar(223); //279
  
      x[282]  = mgr.bddVar(254); //282
  
      x[44]  = mgr.bddVar(37); //44
  
      x[15]  = mgr.bddVar(44); //15
  
      x[303]  = mgr.bddVar(194); //303
  
      x[14]  = mgr.bddVar(45); //14
  
      x[46]  = mgr.bddVar(96); //46
  
      x[304]  = mgr.bddVar(200); //304
  
      x[202]  = mgr.bddVar(201); //202
  
      x[203]  = mgr.bddVar(202); //203
  
      x[299]  = mgr.bddVar(231); //299
  
      x[269]  = mgr.bddVar(241); //269
  
      x[18]  = mgr.bddVar(40); //18
  
      x[17]  = mgr.bddVar(38); //17
  
      x[19]  = mgr.bddVar(39); //19
  
      x[21]  = mgr.bddVar(17); //21
  
      x[20]  = mgr.bddVar(18); //20
  
      x[25]  = mgr.bddVar(9); //25
  
      x[24]  = mgr.bddVar(11); //24
  
      x[33]  = mgr.bddVar(12); //33
  
      x[31]  = mgr.bddVar(16); //31
  
      x[35]  = mgr.bddVar(15); //35
  
      x[34]  = mgr.bddVar(13); //34
  
      x[36]  = mgr.bddVar(14); //36
  
      x[40]  = mgr.bddVar(53); //40
  
      x[38]  = mgr.bddVar(65); //38
  
      x[42]  = mgr.bddVar(55); //42
  
      x[41]  = mgr.bddVar(54); //41
  
      x[23]  = mgr.bddVar(7); //23
  
      x[22]  = mgr.bddVar(10); //22
  
      x[37]  = mgr.bddVar(19); //37
  
      x[45]  = mgr.bddVar(21); //45
  
      x[27]  = mgr.bddVar(3); //27
  
      x[26]  = mgr.bddVar(4); //26
  
      x[29]  = mgr.bddVar(6); //29
  
      x[28]  = mgr.bddVar(5); //28
  
      x[30]  = mgr.bddVar(8); //30
  
      x[43]  = mgr.bddVar(20); //43
  
      x[322]  = mgr.bddVar(284); //322
  
      x[321]  = mgr.bddVar(282); //321
  
      x[324]  = mgr.bddVar(283); //324
  
      x[320]  = mgr.bddVar(266); //320
  
      x[325]  = mgr.bddVar(286); //325
  
      x[327]  = mgr.bddVar(287); //327
  
      x[326]  = mgr.bddVar(267); //326
  
      x[329]  = mgr.bddVar(289); //329
  
      x[328]  = mgr.bddVar(288); //328
  
      x[323]  = mgr.bddVar(285); //323
  


  
  Cudd_MakeTreeNode(mgr.getManager(),0,1012,MTR_DEFAULT);
  

  //Gates
  std::cerr<<"Generating bdd ..."<<std::endl;


  t1 = get_user_time();
  					
	std::cerr<<"procesing gate 338..."<<std::endl;
	x[338] = (!x[4]|x[2]);// and (not _id_1 or homepage) 
	count_nodes_vector.push_back(x[338]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(338);
				
	std::cerr<<"procesing gate 346..."<<std::endl;
	x[346] = (!x[8]|x[6]);// and (not _id_5 or _id_3) 
	count_nodes_vector.push_back(x[346]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(346);
	
	std::cerr<<"procesing gate 348..."<<std::endl;
	x[348] = (!x[9]|x[6]);// and (not special_offers or _id_3) 
	count_nodes_vector.push_back(x[348]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(348);
	
	std::cerr<<"procesing gate 345..."<<std::endl;
	x[345] = (!x[6]|(x[8]|x[9]));// and (not _id_3 or (_id_5 or special_offers)) 
	count_nodes_vector.push_back(x[345]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(345);
	std::cerr<<"procesing gate 344..."<<std::endl;
	x[344] = x[346]&x[348]&x[345];//
	count_nodes_vector.push_back(x[344]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(344);
	
	std::cerr<<"procesing gate 343..."<<std::endl;
	x[343] = (!x[6]|x[5])&(!x[5]|x[6]);// and (not _id_3 or _id_2) and (not _id_2 or _id_3) 
	count_nodes_vector.push_back(x[343]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(343);
	std::cerr<<"procesing gate 342..."<<std::endl;
	x[342] = x[344]&x[343];//
	count_nodes_vector.push_back(x[342]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(342);
			
	std::cerr<<"procesing gate 354..."<<std::endl;
	x[354] = (!x[12]|x[10]);// and (not _id_8 or _id_6) 
	count_nodes_vector.push_back(x[354]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(354);
	
	std::cerr<<"procesing gate 356..."<<std::endl;
	x[356] = (!x[13]|x[10]);// and (not _id_9 or _id_6) 
	count_nodes_vector.push_back(x[356]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(356);
	
	std::cerr<<"procesing gate 353..."<<std::endl;
	x[353] = (!x[10]|(x[12]|x[13]));// and (not _id_6 or (_id_8 or _id_9)) 
	count_nodes_vector.push_back(x[353]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(353);
	std::cerr<<"procesing gate 352..."<<std::endl;
	x[352] = x[354]&x[356]&x[353];//
	count_nodes_vector.push_back(x[352]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(352);
	
	std::cerr<<"procesing gate 351..."<<std::endl;
	x[351] = (!x[10]|x[5])&(!x[5]|x[10]);// and (not _id_6 or _id_2) and (not _id_2 or _id_6) 
	count_nodes_vector.push_back(x[351]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(351);
	std::cerr<<"procesing gate 350..."<<std::endl;
	x[350] = x[352]&x[351];//
	count_nodes_vector.push_back(x[350]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(350);
	
	std::cerr<<"procesing gate 341..."<<std::endl;
	x[341] = (!x[5]|x[2]);// and (not _id_2 or homepage) 
	count_nodes_vector.push_back(x[341]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(341);
	std::cerr<<"procesing gate 340..."<<std::endl;
	x[340] = x[342]&x[350]&x[341];//
	count_nodes_vector.push_back(x[340]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(340);
	
	std::cerr<<"procesing gate 337..."<<std::endl;
	x[337] = (!x[2]|(x[4]|x[5]));// and (not homepage or (_id_1 or _id_2)) 
	count_nodes_vector.push_back(x[337]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(337);
	std::cerr<<"procesing gate 336..."<<std::endl;
	x[336] = x[338]&x[340]&x[337];//
	count_nodes_vector.push_back(x[336]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(336);
	
	std::cerr<<"procesing gate 335..."<<std::endl;
	x[335] = (!x[2]|x[1]);// and (not homepage or store_front) 
	count_nodes_vector.push_back(x[335]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(335);
	std::cerr<<"procesing gate 334..."<<std::endl;
	x[334] = x[336]&x[335];//
	count_nodes_vector.push_back(x[334]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(334);
				
	std::cerr<<"procesing gate 364..."<<std::endl;
	x[364] = (!x[17]|x[15]);// and (not _id_11 or registration_enforcement) 
	count_nodes_vector.push_back(x[364]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(364);
	
	std::cerr<<"procesing gate 366..."<<std::endl;
	x[366] = (!x[18]|x[15]);// and (not register_to_buy or registration_enforcement) 
	count_nodes_vector.push_back(x[366]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(366);
	
	std::cerr<<"procesing gate 368..."<<std::endl;
	x[368] = (!x[19]|x[15]);// and (not _id_12 or registration_enforcement) 
	count_nodes_vector.push_back(x[368]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(368);
	
	std::cerr<<"procesing gate 363..."<<std::endl;
	x[363] = (!x[15]|(x[17]|x[18]|x[19]));// and (not registration_enforcement or (_id_11 or register_to_buy or _id_12)) 
	count_nodes_vector.push_back(x[363]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(363);
	std::cerr<<"procesing gate 362..."<<std::endl;
	x[362] = x[364]&x[366]&x[368]&x[363];//
	count_nodes_vector.push_back(x[362]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(362);
	
	std::cerr<<"procesing gate 361..."<<std::endl;
	x[361] = (!x[15]|x[14])&(!x[14]|x[15]);// and (not registration_enforcement or registration) and (not registration or registration_enforcement) 
	count_nodes_vector.push_back(x[361]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(361);
	std::cerr<<"procesing gate 360..."<<std::endl;
	x[360] = x[362]&x[361];//
	count_nodes_vector.push_back(x[360]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(360);
		
	std::cerr<<"procesing gate 372..."<<std::endl;
	x[372] = (!x[21]|x[20])&(!x[20]|x[21]);// and (not _id_14 or _id_13) and (not _id_13 or _id_14) 
	count_nodes_vector.push_back(x[372]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(372);
		
	std::cerr<<"procesing gate 376..."<<std::endl;
	x[376] = (!x[23]|x[22]);// and (not _id_15 or shipping_address) 
	count_nodes_vector.push_back(x[376]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(376);
	
	std::cerr<<"procesing gate 375..."<<std::endl;
	x[375] = (!x[22]|x[20]);// and (not shipping_address or _id_13) 
	count_nodes_vector.push_back(x[375]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(375);
	std::cerr<<"procesing gate 374..."<<std::endl;
	x[374] = x[376]&x[375];//
	count_nodes_vector.push_back(x[374]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(374);
		
	std::cerr<<"procesing gate 380..."<<std::endl;
	x[380] = (!x[25]|x[24]);// and (not _id_17 or _id_16) 
	count_nodes_vector.push_back(x[380]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(380);
	
	std::cerr<<"procesing gate 379..."<<std::endl;
	x[379] = (!x[24]|x[20]);// and (not _id_16 or _id_13) 
	count_nodes_vector.push_back(x[379]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(379);
	std::cerr<<"procesing gate 378..."<<std::endl;
	x[378] = x[380]&x[379];//
	count_nodes_vector.push_back(x[378]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(378);
		
	std::cerr<<"procesing gate 384..."<<std::endl;
	x[384] = (!x[27]|x[26])&(!x[26]|x[27]);// and (not _id_19 or _id_18) and (not _id_18 or _id_19) 
	count_nodes_vector.push_back(x[384]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(384);
	
	std::cerr<<"procesing gate 386..."<<std::endl;
	x[386] = (!x[28]|x[26])&(!x[26]|x[28]);// and (not _id_20 or _id_18) and (not _id_18 or _id_20) 
	count_nodes_vector.push_back(x[386]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(386);
	
	std::cerr<<"procesing gate 388..."<<std::endl;
	x[388] = (!x[29]|x[26])&(!x[26]|x[29]);// and (not _id_21 or _id_18) and (not _id_18 or _id_21) 
	count_nodes_vector.push_back(x[388]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(388);
	
	std::cerr<<"procesing gate 390..."<<std::endl;
	x[390] = (!x[30]|x[26]);// and (not _id_22 or _id_18) 
	count_nodes_vector.push_back(x[390]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(390);
	
	std::cerr<<"procesing gate 383..."<<std::endl;
	x[383] = (!x[26]|x[20]);// and (not _id_18 or _id_13) 
	count_nodes_vector.push_back(x[383]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(383);
	std::cerr<<"procesing gate 382..."<<std::endl;
	x[382] = x[384]&x[386]&x[388]&x[390]&x[383];//
	count_nodes_vector.push_back(x[382]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(382);
			
	std::cerr<<"procesing gate 396..."<<std::endl;
	x[396] = (!x[33]|x[31]);// and (not _id_25 or _id_23) 
	count_nodes_vector.push_back(x[396]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(396);
	
	std::cerr<<"procesing gate 398..."<<std::endl;
	x[398] = (!x[34]|x[31]);// and (not _id_26 or _id_23) 
	count_nodes_vector.push_back(x[398]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(398);
	
	std::cerr<<"procesing gate 400..."<<std::endl;
	x[400] = (!x[35]|x[31]);// and (not _id_27 or _id_23) 
	count_nodes_vector.push_back(x[400]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(400);
	
	std::cerr<<"procesing gate 402..."<<std::endl;
	x[402] = (!x[36]|x[31]);// and (not _id_28 or _id_23) 
	count_nodes_vector.push_back(x[402]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(402);
	
	std::cerr<<"procesing gate 395..."<<std::endl;
	x[395] = (!x[31]|(x[33]|x[34]|x[35]|x[36]));// and (not _id_23 or (_id_25 or _id_26 or _id_27 or _id_28)) 
	count_nodes_vector.push_back(x[395]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(395);
	std::cerr<<"procesing gate 394..."<<std::endl;
	x[394] = x[396]&x[398]&x[400]&x[402]&x[395];//
	count_nodes_vector.push_back(x[394]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(394);
	
	std::cerr<<"procesing gate 393..."<<std::endl;
	x[393] = (!x[31]|x[20]);// and (not _id_23 or _id_13) 
	count_nodes_vector.push_back(x[393]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(393);
	std::cerr<<"procesing gate 392..."<<std::endl;
	x[392] = x[394]&x[393];//
	count_nodes_vector.push_back(x[392]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(392);
	
	std::cerr<<"procesing gate 404..."<<std::endl;
	x[404] = (!x[37]|x[20]);// and (not _id_29 or _id_13) 
	count_nodes_vector.push_back(x[404]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(404);
			
	std::cerr<<"procesing gate 410..."<<std::endl;
	x[410] = (!x[40]|x[38]);// and (not _id_31 or preferences) 
	count_nodes_vector.push_back(x[410]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(410);
	
	std::cerr<<"procesing gate 412..."<<std::endl;
	x[412] = (!x[41]|x[38]);// and (not _id_32 or preferences) 
	count_nodes_vector.push_back(x[412]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(412);
	
	std::cerr<<"procesing gate 414..."<<std::endl;
	x[414] = (!x[42]|x[38]);// and (not _id_33 or preferences) 
	count_nodes_vector.push_back(x[414]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(414);
	
	std::cerr<<"procesing gate 409..."<<std::endl;
	x[409] = (!x[38]|(x[40]|x[41]|x[42]));// and (not preferences or (_id_31 or _id_32 or _id_33)) 
	count_nodes_vector.push_back(x[409]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(409);
	std::cerr<<"procesing gate 408..."<<std::endl;
	x[408] = x[410]&x[412]&x[414]&x[409];//
	count_nodes_vector.push_back(x[408]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(408);
	
	std::cerr<<"procesing gate 407..."<<std::endl;
	x[407] = (!x[38]|x[20]);// and (not preferences or _id_13) 
	count_nodes_vector.push_back(x[407]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(407);
	std::cerr<<"procesing gate 406..."<<std::endl;
	x[406] = x[408]&x[407];//
	count_nodes_vector.push_back(x[406]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(406);
	
	std::cerr<<"procesing gate 416..."<<std::endl;
	x[416] = (!x[43]|x[20]);// and (not _id_34 or _id_13) 
	count_nodes_vector.push_back(x[416]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(416);
	
	std::cerr<<"procesing gate 418..."<<std::endl;
	x[418] = (!x[44]|x[20]);// and (not quick_checkout_profile or _id_13) 
	count_nodes_vector.push_back(x[418]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(418);
	
	std::cerr<<"procesing gate 420..."<<std::endl;
	x[420] = (!x[45]|x[20]);// and (not _id_35 or _id_13) 
	count_nodes_vector.push_back(x[420]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(420);
	
	std::cerr<<"procesing gate 371..."<<std::endl;
	x[371] = (!x[20]|x[14])&(!x[14]|x[20]);// and (not _id_13 or registration) and (not registration or _id_13) 
	count_nodes_vector.push_back(x[371]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(371);
	std::cerr<<"procesing gate 370..."<<std::endl;
	x[370] = x[372]&x[374]&x[378]&x[382]&x[392]&x[404]&x[406]&x[416]&x[418]&x[420]&x[371];//
	count_nodes_vector.push_back(x[370]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(370);
	
	std::cerr<<"procesing gate 422..."<<std::endl;
	x[422] = (!x[46]|x[14]);// and (not user_behaviour_tracking_info or registration) 
	count_nodes_vector.push_back(x[422]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(422);
	
	std::cerr<<"procesing gate 359..."<<std::endl;
	x[359] = (!x[14]|x[1]);// and (not registration or store_front) 
	count_nodes_vector.push_back(x[359]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(359);
	std::cerr<<"procesing gate 358..."<<std::endl;
	x[358] = x[360]&x[370]&x[422]&x[359];//
	count_nodes_vector.push_back(x[358]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(358);
					
	std::cerr<<"procesing gate 432..."<<std::endl;
	x[432] = (!x[51]|x[49]);// and (not eletronic_goods or product_type) 
	count_nodes_vector.push_back(x[432]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(432);
	
	std::cerr<<"procesing gate 434..."<<std::endl;
	x[434] = (!x[52]|x[49]);// and (not physical_goods or product_type) 
	count_nodes_vector.push_back(x[434]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(434);
	
	std::cerr<<"procesing gate 436..."<<std::endl;
	x[436] = (!x[53]|x[49]);// and (not services or product_type) 
	count_nodes_vector.push_back(x[436]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(436);
	
	std::cerr<<"procesing gate 431..."<<std::endl;
	x[431] = (!x[49]|(x[51]|x[52]|x[53]));// and (not product_type or (eletronic_goods or physical_goods or services)) 
	count_nodes_vector.push_back(x[431]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(431);
	std::cerr<<"procesing gate 430..."<<std::endl;
	x[430] = x[432]&x[434]&x[436]&x[431];//
	count_nodes_vector.push_back(x[430]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(430);
	
	std::cerr<<"procesing gate 429..."<<std::endl;
	x[429] = (!x[49]|x[48])&(!x[48]|x[49]);// and (not product_type or product_information) and (not product_information or product_type) 
	count_nodes_vector.push_back(x[429]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(429);
	std::cerr<<"procesing gate 428..."<<std::endl;
	x[428] = x[430]&x[429];//
	count_nodes_vector.push_back(x[428]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(428);
	
	std::cerr<<"procesing gate 438..."<<std::endl;
	x[438] = (!x[54]|x[48])&(!x[48]|x[54]);// and (not basic_information or product_information) and (not product_information or basic_information) 
	count_nodes_vector.push_back(x[438]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(438);
	
	std::cerr<<"procesing gate 440..."<<std::endl;
	x[440] = (!x[55]|x[48]);// and (not detailed_information or product_information) 
	count_nodes_vector.push_back(x[440]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(440);
	
	std::cerr<<"procesing gate 442..."<<std::endl;
	x[442] = (!x[56]|x[48]);// and (not warranty_information or product_information) 
	count_nodes_vector.push_back(x[442]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(442);
	
	std::cerr<<"procesing gate 444..."<<std::endl;
	x[444] = (!x[57]|x[48]);// and (not customer_reviews or product_information) 
	count_nodes_vector.push_back(x[444]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(444);
			
	std::cerr<<"procesing gate 450..."<<std::endl;
	x[450] = (!x[60]|x[58]);// and (not _id_38 or associated_assets) 
	count_nodes_vector.push_back(x[450]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(450);
					
	std::cerr<<"procesing gate 460..."<<std::endl;
	x[460] = (!x[65]|x[63]);// and (not _id_43 or _id_41) 
	count_nodes_vector.push_back(x[460]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(460);
	
	std::cerr<<"procesing gate 462..."<<std::endl;
	x[462] = (!x[66]|x[63]);// and (not _id_44 or _id_41) 
	count_nodes_vector.push_back(x[462]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(462);
	
	std::cerr<<"procesing gate 464..."<<std::endl;
	x[464] = (!x[67]|x[63]);// and (not _id_45 or _id_41) 
	count_nodes_vector.push_back(x[464]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(464);
	
	std::cerr<<"procesing gate 466..."<<std::endl;
	x[466] = (!x[68]|x[63]);// and (not _id_46 or _id_41) 
	count_nodes_vector.push_back(x[466]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(466);
	
	std::cerr<<"procesing gate 468..."<<std::endl;
	x[468] = (!x[69]|x[63]);// and (not _id_47 or _id_41) 
	count_nodes_vector.push_back(x[468]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(468);
	
	std::cerr<<"procesing gate 470..."<<std::endl;
	x[470] = (!x[70]|x[63]);// and (not _id_48 or _id_41) 
	count_nodes_vector.push_back(x[470]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(470);
	
	std::cerr<<"procesing gate 459..."<<std::endl;
	x[459] = (!x[63]|(x[65]|x[66]|x[67]|x[68]|x[69]|x[70]));// and (not _id_41 or (_id_43 or _id_44 or _id_45 or _id_46 or _id_47 or _id_48)) 
	count_nodes_vector.push_back(x[459]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(459);
	std::cerr<<"procesing gate 458..."<<std::endl;
	x[458] = x[460]&x[462]&x[464]&x[466]&x[468]&x[470]&x[459];//
	count_nodes_vector.push_back(x[458]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(458);
	
	std::cerr<<"procesing gate 457..."<<std::endl;
	x[457] = (!x[63]|x[61]);// and (not _id_41 or _id_39) 
	count_nodes_vector.push_back(x[457]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(457);
	std::cerr<<"procesing gate 456..."<<std::endl;
	x[456] = x[458]&x[457];//
	count_nodes_vector.push_back(x[456]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(456);
	
	std::cerr<<"procesing gate 472..."<<std::endl;
	x[472] = (!x[71]|x[61]);// and (not _id_49 or _id_39) 
	count_nodes_vector.push_back(x[472]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(472);
	
	std::cerr<<"procesing gate 474..."<<std::endl;
	x[474] = (!x[72]|x[61]);// and (not _id_50 or _id_39) 
	count_nodes_vector.push_back(x[474]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(474);
	
	std::cerr<<"procesing gate 455..."<<std::endl;
	x[455] = (!x[61]|(x[63]|x[71]|x[72]));// and (not _id_39 or (_id_41 or _id_49 or _id_50)) 
	count_nodes_vector.push_back(x[455]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(455);
	std::cerr<<"procesing gate 454..."<<std::endl;
	x[454] = x[456]&x[472]&x[474]&x[455];//
	count_nodes_vector.push_back(x[454]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(454);
	
	std::cerr<<"procesing gate 453..."<<std::endl;
	x[453] = (!x[61]|x[58]);// and (not _id_39 or associated_assets) 
	count_nodes_vector.push_back(x[453]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(453);
	std::cerr<<"procesing gate 452..."<<std::endl;
	x[452] = x[454]&x[453];//
	count_nodes_vector.push_back(x[452]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(452);
	
	std::cerr<<"procesing gate 449..."<<std::endl;
	x[449] = (!x[58]|(x[60]|x[61]));// and (not associated_assets or (_id_38 or _id_39)) 
	count_nodes_vector.push_back(x[449]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(449);
	std::cerr<<"procesing gate 448..."<<std::endl;
	x[448] = x[450]&x[452]&x[449];//
	count_nodes_vector.push_back(x[448]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(448);
	
	std::cerr<<"procesing gate 447..."<<std::endl;
	x[447] = (!x[58]|x[48]);// and (not associated_assets or product_information) 
	count_nodes_vector.push_back(x[447]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(447);
	std::cerr<<"procesing gate 446..."<<std::endl;
	x[446] = x[448]&x[447];//
	count_nodes_vector.push_back(x[446]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(446);
		
	std::cerr<<"procesing gate 478..."<<std::endl;
	x[478] = (!x[74]|x[73]);// and (not _id_51 or product_variants) 
	count_nodes_vector.push_back(x[478]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(478);
	
	std::cerr<<"procesing gate 477..."<<std::endl;
	x[477] = (!x[73]|x[48]);// and (not product_variants or product_information) 
	count_nodes_vector.push_back(x[477]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(477);
	std::cerr<<"procesing gate 476..."<<std::endl;
	x[476] = x[478]&x[477];//
	count_nodes_vector.push_back(x[476]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(476);
	
	std::cerr<<"procesing gate 480..."<<std::endl;
	x[480] = (!x[75]|x[48]);// and (not size or product_information) 
	count_nodes_vector.push_back(x[480]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(480);
	
	std::cerr<<"procesing gate 482..."<<std::endl;
	x[482] = (!x[76]|x[48]);// and (not weight or product_information) 
	count_nodes_vector.push_back(x[482]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(482);
	
	std::cerr<<"procesing gate 484..."<<std::endl;
	x[484] = (!x[77]|x[48]);// and (not availability or product_information) 
	count_nodes_vector.push_back(x[484]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(484);
	
	std::cerr<<"procesing gate 486..."<<std::endl;
	x[486] = (!x[78]|x[48]);// and (not custom_fields or product_information) 
	count_nodes_vector.push_back(x[486]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(486);
	
	std::cerr<<"procesing gate 427..."<<std::endl;
	x[427] = (!x[48]|x[47])&(!x[47]|x[48]);// and (not product_information or catalog) and (not catalog or product_information) 
	count_nodes_vector.push_back(x[427]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(427);
	std::cerr<<"procesing gate 426..."<<std::endl;
	x[426] = x[428]&x[438]&x[440]&x[442]&x[444]&x[446]&x[476]&x[480]&x[482]&x[484]&x[486]&x[427];//
	count_nodes_vector.push_back(x[426]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(426);
				
	std::cerr<<"procesing gate 494..."<<std::endl;
	x[494] = (!x[82]|x[81]);// and (not _id_53 or _id_52) 
	count_nodes_vector.push_back(x[494]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(494);
	
	std::cerr<<"procesing gate 496..."<<std::endl;
	x[496] = (!x[83]|x[81]);// and (not _id_54 or _id_52) 
	count_nodes_vector.push_back(x[496]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(496);
	
	std::cerr<<"procesing gate 493..."<<std::endl;
	x[493] = (!x[81]|x[80]);// and (not _id_52 or categories_catalog) 
	count_nodes_vector.push_back(x[493]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(493);
	std::cerr<<"procesing gate 492..."<<std::endl;
	x[492] = x[494]&x[496]&x[493];//
	count_nodes_vector.push_back(x[492]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(492);
	
	std::cerr<<"procesing gate 491..."<<std::endl;
	x[491] = (!x[80]|x[79])&(!x[79]|x[80]);// and (not categories_catalog or categories) and (not categories or categories_catalog) 
	count_nodes_vector.push_back(x[491]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(491);
	std::cerr<<"procesing gate 490..."<<std::endl;
	x[490] = x[492]&x[491];//
	count_nodes_vector.push_back(x[490]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(490);
	
	std::cerr<<"procesing gate 489..."<<std::endl;
	x[489] = (!x[79]|x[47]);// and (not categories or catalog) 
	count_nodes_vector.push_back(x[489]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(489);
	std::cerr<<"procesing gate 488..."<<std::endl;
	x[488] = x[490]&x[489];//
	count_nodes_vector.push_back(x[488]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(488);
	
	std::cerr<<"procesing gate 498..."<<std::endl;
	x[498] = (!x[84]|x[47]);// and (not _id_55 or catalog) 
	count_nodes_vector.push_back(x[498]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(498);
			
	std::cerr<<"procesing gate 504..."<<std::endl;
	x[504] = (!x[87]|x[85]);// and (not _id_58 or _id_56) 
	count_nodes_vector.push_back(x[504]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(504);
	
	std::cerr<<"procesing gate 506..."<<std::endl;
	x[506] = (!x[88]|x[85]);// and (not _id_59 or _id_56) 
	count_nodes_vector.push_back(x[506]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(506);
	
	std::cerr<<"procesing gate 503..."<<std::endl;
	x[503] = (!x[85]|(x[87]|x[88]));// and (not _id_56 or (_id_58 or _id_59)) 
	count_nodes_vector.push_back(x[503]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(503);
	std::cerr<<"procesing gate 502..."<<std::endl;
	x[502] = x[504]&x[506]&x[503];//
	count_nodes_vector.push_back(x[502]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(502);
	
	std::cerr<<"procesing gate 501..."<<std::endl;
	x[501] = (!x[85]|x[47]);// and (not _id_56 or catalog) 
	count_nodes_vector.push_back(x[501]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(501);
	std::cerr<<"procesing gate 500..."<<std::endl;
	x[500] = x[502]&x[501];//
	count_nodes_vector.push_back(x[500]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(500);
		
	std::cerr<<"procesing gate 510..."<<std::endl;
	x[510] = (!x[90]|x[89])&(!x[89]|x[90]);// and (not _id_61 or _id_60) and (not _id_60 or _id_61) 
	count_nodes_vector.push_back(x[510]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(510);
	
	std::cerr<<"procesing gate 512..."<<std::endl;
	x[512] = (!x[91]|x[89]);// and (not category_page or _id_60) 
	count_nodes_vector.push_back(x[512]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(512);
				
	std::cerr<<"procesing gate 520..."<<std::endl;
	x[520] = (!x[95]|x[93]);// and (not _id_65 or _id_63) 
	count_nodes_vector.push_back(x[520]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(520);
	
	std::cerr<<"procesing gate 522..."<<std::endl;
	x[522] = (!x[96]|x[93]);// and (not _id_66 or _id_63) 
	count_nodes_vector.push_back(x[522]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(522);
	
	std::cerr<<"procesing gate 524..."<<std::endl;
	x[524] = (!x[97]|x[93]);// and (not _id_67 or _id_63) 
	count_nodes_vector.push_back(x[524]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(524);
	
	std::cerr<<"procesing gate 526..."<<std::endl;
	x[526] = (!x[98]|x[93]);// and (not _id_68 or _id_63) 
	count_nodes_vector.push_back(x[526]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(526);
	
	std::cerr<<"procesing gate 528..."<<std::endl;
	x[528] = (!x[99]|x[93]);// and (not _id_69 or _id_63) 
	count_nodes_vector.push_back(x[528]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(528);
	
	std::cerr<<"procesing gate 519..."<<std::endl;
	x[519] = (!x[93]|(x[95]|x[96]|x[97]|x[98]|x[99]));// and (not _id_63 or (_id_65 or _id_66 or _id_67 or _id_68 or _id_69)) 
	count_nodes_vector.push_back(x[519]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(519);
	std::cerr<<"procesing gate 518..."<<std::endl;
	x[518] = x[520]&x[522]&x[524]&x[526]&x[528]&x[519];//
	count_nodes_vector.push_back(x[518]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(518);
	
	std::cerr<<"procesing gate 517..."<<std::endl;
	x[517] = (!x[93]|x[92]);// and (not _id_63 or _id_62) 
	count_nodes_vector.push_back(x[517]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(517);
	std::cerr<<"procesing gate 516..."<<std::endl;
	x[516] = x[518]&x[517];//
	count_nodes_vector.push_back(x[516]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(516);
	
	std::cerr<<"procesing gate 515..."<<std::endl;
	x[515] = (!x[92]|x[89]);// and (not _id_62 or _id_60) 
	count_nodes_vector.push_back(x[515]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(515);
	std::cerr<<"procesing gate 514..."<<std::endl;
	x[514] = x[516]&x[515];//
	count_nodes_vector.push_back(x[514]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(514);
	
	std::cerr<<"procesing gate 509..."<<std::endl;
	x[509] = (!x[89]|x[47]);// and (not _id_60 or catalog) 
	count_nodes_vector.push_back(x[509]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(509);
	std::cerr<<"procesing gate 508..."<<std::endl;
	x[508] = x[510]&x[512]&x[514]&x[509];//
	count_nodes_vector.push_back(x[508]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(508);
		
	std::cerr<<"procesing gate 532..."<<std::endl;
	x[532] = (!x[101]|x[100]);// and (not _id_71 or _id_70) 
	count_nodes_vector.push_back(x[532]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(532);
	
	std::cerr<<"procesing gate 534..."<<std::endl;
	x[534] = (!x[102]|x[100]);// and (not _id_72 or _id_70) 
	count_nodes_vector.push_back(x[534]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(534);
	
	std::cerr<<"procesing gate 531..."<<std::endl;
	x[531] = (!x[100]|x[47]);// and (not _id_70 or catalog) 
	count_nodes_vector.push_back(x[531]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(531);
	std::cerr<<"procesing gate 530..."<<std::endl;
	x[530] = x[532]&x[534]&x[531];//
	count_nodes_vector.push_back(x[530]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(530);
	
	std::cerr<<"procesing gate 425..."<<std::endl;
	x[425] = (!x[47]|x[1])&(!x[1]|x[47]);// and (not catalog or store_front) and (not store_front or catalog) 
	count_nodes_vector.push_back(x[425]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(425);
	std::cerr<<"procesing gate 424..."<<std::endl;
	x[424] = x[426]&x[488]&x[498]&x[500]&x[508]&x[530]&x[425];//
	count_nodes_vector.push_back(x[424]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(424);
		
	std::cerr<<"procesing gate 538..."<<std::endl;
	x[538] = (!x[104]|x[103]);// and (not wish_list_saved_after_session or wish_list) 
	count_nodes_vector.push_back(x[538]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(538);
	
	std::cerr<<"procesing gate 540..."<<std::endl;
	x[540] = (!x[105]|x[103]);// and (not email_wish_list or wish_list) 
	count_nodes_vector.push_back(x[540]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(540);
	
	std::cerr<<"procesing gate 542..."<<std::endl;
	x[542] = (!x[106]|x[103]);// and (not _id_73 or wish_list) 
	count_nodes_vector.push_back(x[542]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(542);
			
	std::cerr<<"procesing gate 548..."<<std::endl;
	x[548] = (!x[109]|x[107]);// and (not _id_75 or permissions) 
	count_nodes_vector.push_back(x[548]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(548);
	
	std::cerr<<"procesing gate 550..."<<std::endl;
	x[550] = (!x[110]|x[107]);// and (not _id_76 or permissions) 
	count_nodes_vector.push_back(x[550]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(550);
	
	std::cerr<<"procesing gate 552..."<<std::endl;
	x[552] = (!x[111]|x[107]);// and (not _id_77 or permissions) 
	count_nodes_vector.push_back(x[552]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(552);
	
	std::cerr<<"procesing gate 547..."<<std::endl;
	x[547] = (!x[107]|(x[109]|x[110]|x[111]));// and (not permissions or (_id_75 or _id_76 or _id_77)) 
	count_nodes_vector.push_back(x[547]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(547);
	std::cerr<<"procesing gate 546..."<<std::endl;
	x[546] = x[548]&x[550]&x[552]&x[547];//
	count_nodes_vector.push_back(x[546]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(546);
	
	std::cerr<<"procesing gate 545..."<<std::endl;
	x[545] = (!x[107]|x[103]);// and (not permissions or wish_list) 
	count_nodes_vector.push_back(x[545]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(545);
	std::cerr<<"procesing gate 544..."<<std::endl;
	x[544] = x[546]&x[545];//
	count_nodes_vector.push_back(x[544]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(544);
	
	std::cerr<<"procesing gate 537..."<<std::endl;
	x[537] = (!x[103]|x[1]);// and (not wish_list or store_front) 
	count_nodes_vector.push_back(x[537]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(537);
	std::cerr<<"procesing gate 536..."<<std::endl;
	x[536] = x[538]&x[540]&x[542]&x[544]&x[537];//
	count_nodes_vector.push_back(x[536]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(536);
			
	std::cerr<<"procesing gate 558..."<<std::endl;
	x[558] = (!x[114]|x[113])&(!x[113]|x[114]);// and (not _id_79 or _id_78) and (not _id_78 or _id_79) 
	count_nodes_vector.push_back(x[558]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(558);
	
	std::cerr<<"procesing gate 560..."<<std::endl;
	x[560] = (!x[115]|x[113])&(!x[113]|x[115]);// and (not _id_80 or _id_78) and (not _id_78 or _id_80) 
	count_nodes_vector.push_back(x[560]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(560);
	
	std::cerr<<"procesing gate 562..."<<std::endl;
	x[562] = (!x[116]|x[113]);// and (not _id_81 or _id_78) 
	count_nodes_vector.push_back(x[562]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(562);
	
	std::cerr<<"procesing gate 564..."<<std::endl;
	x[564] = (!x[117]|x[113]);// and (not _id_82 or _id_78) 
	count_nodes_vector.push_back(x[564]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(564);
	
	std::cerr<<"procesing gate 557..."<<std::endl;
	x[557] = (!x[113]|x[112])&(!x[112]|x[113]);// and (not _id_78 or buy_paths) and (not buy_paths or _id_78) 
	count_nodes_vector.push_back(x[557]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(557);
	std::cerr<<"procesing gate 556..."<<std::endl;
	x[556] = x[558]&x[560]&x[562]&x[564]&x[557];//
	count_nodes_vector.push_back(x[556]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(556);
						
	std::cerr<<"procesing gate 576..."<<std::endl;
	x[576] = (!x[123]|x[122]);// and (not _id_86 or quick_checkout) 
	count_nodes_vector.push_back(x[576]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(576);
	
	std::cerr<<"procesing gate 575..."<<std::endl;
	x[575] = (!x[122]|x[121]);// and (not quick_checkout or registered_checkout) 
	count_nodes_vector.push_back(x[575]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(575);
	std::cerr<<"procesing gate 574..."<<std::endl;
	x[574] = x[576]&x[575];//
	count_nodes_vector.push_back(x[574]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(574);
	
	std::cerr<<"procesing gate 573..."<<std::endl;
	x[573] = (!x[121]|x[119]);// and (not registered_checkout or _id_84) 
	count_nodes_vector.push_back(x[573]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(573);
	std::cerr<<"procesing gate 572..."<<std::endl;
	x[572] = x[574]&x[573];//
	count_nodes_vector.push_back(x[572]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(572);
	
	std::cerr<<"procesing gate 578..."<<std::endl;
	x[578] = (!x[124]|x[119]);// and (not _id_87 or _id_84) 
	count_nodes_vector.push_back(x[578]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(578);
	
	std::cerr<<"procesing gate 571..."<<std::endl;
	x[571] = (!x[119]|(x[121]|x[124]));// and (not _id_84 or (registered_checkout or _id_87)) 
	count_nodes_vector.push_back(x[571]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(571);
	std::cerr<<"procesing gate 570..."<<std::endl;
	x[570] = x[572]&x[578]&x[571];//
	count_nodes_vector.push_back(x[570]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(570);
	
	std::cerr<<"procesing gate 569..."<<std::endl;
	x[569] = (!x[119]|x[118])&(!x[118]|x[119]);// and (not _id_84 or _id_83) and (not _id_83 or _id_84) 
	count_nodes_vector.push_back(x[569]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(569);
	std::cerr<<"procesing gate 568..."<<std::endl;
	x[568] = x[570]&x[569];//
	count_nodes_vector.push_back(x[568]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(568);
		
	std::cerr<<"procesing gate 582..."<<std::endl;
	x[582] = (!x[126]|x[125]);// and (not _id_88 or shipping_options) 
	count_nodes_vector.push_back(x[582]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(582);
	
	std::cerr<<"procesing gate 584..."<<std::endl;
	x[584] = (!x[127]|x[125]);// and (not _id_89 or shipping_options) 
	count_nodes_vector.push_back(x[584]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(584);
	
	std::cerr<<"procesing gate 586..."<<std::endl;
	x[586] = (!x[128]|x[125]);// and (not _id_90 or shipping_options) 
	count_nodes_vector.push_back(x[586]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(586);
	
	std::cerr<<"procesing gate 588..."<<std::endl;
	x[588] = (!x[129]|x[125]);// and (not _id_91 or shipping_options) 
	count_nodes_vector.push_back(x[588]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(588);
	
	std::cerr<<"procesing gate 590..."<<std::endl;
	x[590] = (!x[130]|x[125])&(!x[125]|x[130]);// and (not _id_92 or shipping_options) and (not shipping_options or _id_92) 
	count_nodes_vector.push_back(x[590]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(590);
	
	std::cerr<<"procesing gate 581..."<<std::endl;
	x[581] = (!x[125]|x[118]);// and (not shipping_options or _id_83) 
	count_nodes_vector.push_back(x[581]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(581);
	std::cerr<<"procesing gate 580..."<<std::endl;
	x[580] = x[582]&x[584]&x[586]&x[588]&x[590]&x[581];//
	count_nodes_vector.push_back(x[580]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(580);
						
	std::cerr<<"procesing gate 602..."<<std::endl;
	x[602] = (!x[136]|x[134]);// and (not _id_98 or _id_96) 
	count_nodes_vector.push_back(x[602]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(602);
		
	std::cerr<<"procesing gate 606..."<<std::endl;
	x[606] = (!x[138]|x[137])&(!x[137]|x[138]);// and (not _id_100 or _id_99) and (not _id_99 or _id_100) 
	count_nodes_vector.push_back(x[606]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(606);
		
	std::cerr<<"procesing gate 610..."<<std::endl;
	x[610] = (!x[140]|x[139])&(!x[139]|x[140]);// and (not shipping_2 or _id_101) and (not _id_101 or shipping_2) 
	count_nodes_vector.push_back(x[610]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(610);
	
	std::cerr<<"procesing gate 612..."<<std::endl;
	x[612] = (!x[141]|x[139]);// and (not _id_102 or _id_101) 
	count_nodes_vector.push_back(x[612]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(612);
	
	std::cerr<<"procesing gate 609..."<<std::endl;
	x[609] = (!x[139]|x[137])&(!x[137]|x[139]);// and (not _id_101 or _id_99) and (not _id_99 or _id_101) 
	count_nodes_vector.push_back(x[609]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(609);
	std::cerr<<"procesing gate 608..."<<std::endl;
	x[608] = x[610]&x[612]&x[609];//
	count_nodes_vector.push_back(x[608]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(608);
			
	std::cerr<<"procesing gate 618..."<<std::endl;
	x[618] = (!x[144]|x[142]);// and (not _id_105 or _id_103) 
	count_nodes_vector.push_back(x[618]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(618);
	
	std::cerr<<"procesing gate 620..."<<std::endl;
	x[620] = (!x[145]|x[142]);// and (not _id_106 or _id_103) 
	count_nodes_vector.push_back(x[620]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(620);
	
	std::cerr<<"procesing gate 622..."<<std::endl;
	x[622] = (!x[146]|x[142]);// and (not _id_107 or _id_103) 
	count_nodes_vector.push_back(x[622]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(622);
	
	std::cerr<<"procesing gate 617..."<<std::endl;
	x[617] = (!x[142]|(x[144]|x[145]|x[146]));// and (not _id_103 or (_id_105 or _id_106 or _id_107)) 
	count_nodes_vector.push_back(x[617]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(617);
	std::cerr<<"procesing gate 616..."<<std::endl;
	x[616] = x[618]&x[620]&x[622]&x[617];//
	count_nodes_vector.push_back(x[616]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(616);
	
	std::cerr<<"procesing gate 615..."<<std::endl;
	x[615] = (!x[142]|x[137]);// and (not _id_103 or _id_99) 
	count_nodes_vector.push_back(x[615]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(615);
	std::cerr<<"procesing gate 614..."<<std::endl;
	x[614] = x[616]&x[615];//
	count_nodes_vector.push_back(x[614]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(614);
	
	std::cerr<<"procesing gate 605..."<<std::endl;
	x[605] = (!x[137]|x[134]);// and (not _id_99 or _id_96) 
	count_nodes_vector.push_back(x[605]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(605);
	std::cerr<<"procesing gate 604..."<<std::endl;
	x[604] = x[606]&x[608]&x[614]&x[605];//
	count_nodes_vector.push_back(x[604]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(604);
	
	std::cerr<<"procesing gate 601..."<<std::endl;
	x[601] = (!x[134]|(x[136]|x[137]));// and (not _id_96 or (_id_98 or _id_99)) 
	count_nodes_vector.push_back(x[601]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(601);
	std::cerr<<"procesing gate 600..."<<std::endl;
	x[600] = x[602]&x[604]&x[601];//
	count_nodes_vector.push_back(x[600]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(600);
	
	std::cerr<<"procesing gate 599..."<<std::endl;
	x[599] = (!x[134]|x[133])&(!x[133]|x[134]);// and (not _id_96 or _id_95) and (not _id_95 or _id_96) 
	count_nodes_vector.push_back(x[599]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(599);
	std::cerr<<"procesing gate 598..."<<std::endl;
	x[598] = x[600]&x[599];//
	count_nodes_vector.push_back(x[598]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(598);
			
	std::cerr<<"procesing gate 628..."<<std::endl;
	x[628] = (!x[149]|x[147]);// and (not _id_110 or _id_108) 
	count_nodes_vector.push_back(x[628]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(628);
	
	std::cerr<<"procesing gate 630..."<<std::endl;
	x[630] = (!x[150]|x[147]);// and (not _id_111 or _id_108) 
	count_nodes_vector.push_back(x[630]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(630);
	
	std::cerr<<"procesing gate 627..."<<std::endl;
	x[627] = (!x[147]|(x[149]|x[150]));// and (not _id_108 or (_id_110 or _id_111)) 
	count_nodes_vector.push_back(x[627]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(627);
	std::cerr<<"procesing gate 626..."<<std::endl;
	x[626] = x[628]&x[630]&x[627];//
	count_nodes_vector.push_back(x[626]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(626);
	
	std::cerr<<"procesing gate 625..."<<std::endl;
	x[625] = (!x[147]|x[133])&(!x[133]|x[147]);// and (not _id_108 or _id_95) and (not _id_95 or _id_108) 
	count_nodes_vector.push_back(x[625]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(625);
	std::cerr<<"procesing gate 624..."<<std::endl;
	x[624] = x[626]&x[625];//
	count_nodes_vector.push_back(x[624]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(624);
	
	std::cerr<<"procesing gate 597..."<<std::endl;
	x[597] = (!x[133]|x[131]);// and (not _id_95 or _id_93) 
	count_nodes_vector.push_back(x[597]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(597);
	std::cerr<<"procesing gate 596..."<<std::endl;
	x[596] = x[598]&x[624]&x[597];//
	count_nodes_vector.push_back(x[596]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(596);
			
	std::cerr<<"procesing gate 636..."<<std::endl;
	x[636] = (!x[153]|x[151]);// and (not _id_114 or _id_112) 
	count_nodes_vector.push_back(x[636]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(636);
	
	std::cerr<<"procesing gate 638..."<<std::endl;
	x[638] = (!x[154]|x[151]);// and (not _id_115 or _id_112) 
	count_nodes_vector.push_back(x[638]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(638);
	
	std::cerr<<"procesing gate 640..."<<std::endl;
	x[640] = (!x[155]|x[151]);// and (not _id_116 or _id_112) 
	count_nodes_vector.push_back(x[640]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(640);
	
	std::cerr<<"procesing gate 635..."<<std::endl;
	x[635] = (!x[151]|(x[153]|x[154]|x[155]));// and (not _id_112 or (_id_114 or _id_115 or _id_116)) 
	count_nodes_vector.push_back(x[635]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(635);
	std::cerr<<"procesing gate 634..."<<std::endl;
	x[634] = x[636]&x[638]&x[640]&x[635];//
	count_nodes_vector.push_back(x[634]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(634);
	
	std::cerr<<"procesing gate 633..."<<std::endl;
	x[633] = (!x[151]|x[131]);// and (not _id_112 or _id_93) 
	count_nodes_vector.push_back(x[633]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(633);
	std::cerr<<"procesing gate 632..."<<std::endl;
	x[632] = x[634]&x[633];//
	count_nodes_vector.push_back(x[632]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(632);
	
	std::cerr<<"procesing gate 595..."<<std::endl;
	x[595] = (!x[131]|(x[133]|x[151]));// and (not _id_93 or (_id_95 or _id_112)) 
	count_nodes_vector.push_back(x[595]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(595);
	std::cerr<<"procesing gate 594..."<<std::endl;
	x[594] = x[596]&x[632]&x[595];//
	count_nodes_vector.push_back(x[594]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(594);
	
	std::cerr<<"procesing gate 593..."<<std::endl;
	x[593] = (!x[131]|x[118])&(!x[118]|x[131]);// and (not _id_93 or _id_83) and (not _id_83 or _id_93) 
	count_nodes_vector.push_back(x[593]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(593);
	std::cerr<<"procesing gate 592..."<<std::endl;
	x[592] = x[594]&x[593];//
	count_nodes_vector.push_back(x[592]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(592);
				
	std::cerr<<"procesing gate 648..."<<std::endl;
	x[648] = (!x[159]|x[157]);// and (not _id_120 or _id_118) 
	count_nodes_vector.push_back(x[648]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(648);
	
	std::cerr<<"procesing gate 650..."<<std::endl;
	x[650] = (!x[160]|x[157]);// and (not _id_121 or _id_118) 
	count_nodes_vector.push_back(x[650]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(650);
	
	std::cerr<<"procesing gate 652..."<<std::endl;
	x[652] = (!x[161]|x[157]);// and (not _id_122 or _id_118) 
	count_nodes_vector.push_back(x[652]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(652);
	
	std::cerr<<"procesing gate 654..."<<std::endl;
	x[654] = (!x[162]|x[157]);// and (not _id_123 or _id_118) 
	count_nodes_vector.push_back(x[654]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(654);
	
	std::cerr<<"procesing gate 656..."<<std::endl;
	x[656] = (!x[163]|x[157]);// and (not _id_124 or _id_118) 
	count_nodes_vector.push_back(x[656]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(656);
	
	std::cerr<<"procesing gate 658..."<<std::endl;
	x[658] = (!x[164]|x[157]);// and (not _id_125 or _id_118) 
	count_nodes_vector.push_back(x[658]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(658);
	
	std::cerr<<"procesing gate 660..."<<std::endl;
	x[660] = (!x[165]|x[157]);// and (not _id_126 or _id_118) 
	count_nodes_vector.push_back(x[660]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(660);
	
	std::cerr<<"procesing gate 662..."<<std::endl;
	x[662] = (!x[166]|x[157]);// and (not _id_127 or _id_118) 
	count_nodes_vector.push_back(x[662]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(662);
	
	std::cerr<<"procesing gate 664..."<<std::endl;
	x[664] = (!x[167]|x[157]);// and (not _id_128 or _id_118) 
	count_nodes_vector.push_back(x[664]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(664);
	
	std::cerr<<"procesing gate 647..."<<std::endl;
	x[647] = (!x[157]|(x[159]|x[160]|x[161]|x[162]|x[163]|x[164]|x[165]|x[166]|x[167]));// and (not _id_118 or (_id_120 or _id_121 or _id_122 or _id_123 or _id_124 or _id_125 or _id_126 or _id_127 or _id_128)) 
	count_nodes_vector.push_back(x[647]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(647);
	std::cerr<<"procesing gate 646..."<<std::endl;
	x[646] = x[648]&x[650]&x[652]&x[654]&x[656]&x[658]&x[660]&x[662]&x[664]&x[647];//
	count_nodes_vector.push_back(x[646]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(646);
	
	std::cerr<<"procesing gate 645..."<<std::endl;
	x[645] = (!x[157]|x[156])&(!x[156]|x[157]);// and (not _id_118 or _id_117) and (not _id_117 or _id_118) 
	count_nodes_vector.push_back(x[645]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(645);
	std::cerr<<"procesing gate 644..."<<std::endl;
	x[644] = x[646]&x[645];//
	count_nodes_vector.push_back(x[644]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(644);
	
	std::cerr<<"procesing gate 666..."<<std::endl;
	x[666] = (!x[168]|x[156]);// and (not _id_129 or _id_117) 
	count_nodes_vector.push_back(x[666]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(666);
			
	std::cerr<<"procesing gate 672..."<<std::endl;
	x[672] = (!x[171]|x[169]);// and (not _id_132 or _id_130) 
	count_nodes_vector.push_back(x[672]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(672);
	
	std::cerr<<"procesing gate 674..."<<std::endl;
	x[674] = (!x[172]|x[169]);// and (not _id_133 or _id_130) 
	count_nodes_vector.push_back(x[674]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(674);
	
	std::cerr<<"procesing gate 676..."<<std::endl;
	x[676] = (!x[173]|x[169]);// and (not _id_134 or _id_130) 
	count_nodes_vector.push_back(x[676]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(676);
	
	std::cerr<<"procesing gate 678..."<<std::endl;
	x[678] = (!x[174]|x[169]);// and (not _id_135 or _id_130) 
	count_nodes_vector.push_back(x[678]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(678);
	
	std::cerr<<"procesing gate 680..."<<std::endl;
	x[680] = (!x[175]|x[169]);// and (not _id_136 or _id_130) 
	count_nodes_vector.push_back(x[680]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(680);
	
	std::cerr<<"procesing gate 682..."<<std::endl;
	x[682] = (!x[176]|x[169]);// and (not _id_137 or _id_130) 
	count_nodes_vector.push_back(x[682]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(682);
	
	std::cerr<<"procesing gate 684..."<<std::endl;
	x[684] = (!x[177]|x[169]);// and (not _id_138 or _id_130) 
	count_nodes_vector.push_back(x[684]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(684);
	
	std::cerr<<"procesing gate 671..."<<std::endl;
	x[671] = (!x[169]|(x[171]|x[172]|x[173]|x[174]|x[175]|x[176]|x[177]));// and (not _id_130 or (_id_132 or _id_133 or _id_134 or _id_135 or _id_136 or _id_137 or _id_138)) 
	count_nodes_vector.push_back(x[671]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(671);
	std::cerr<<"procesing gate 670..."<<std::endl;
	x[670] = x[672]&x[674]&x[676]&x[678]&x[680]&x[682]&x[684]&x[671];//
	count_nodes_vector.push_back(x[670]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(670);
	
	std::cerr<<"procesing gate 669..."<<std::endl;
	x[669] = (!x[169]|x[156]);// and (not _id_130 or _id_117) 
	count_nodes_vector.push_back(x[669]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(669);
	std::cerr<<"procesing gate 668..."<<std::endl;
	x[668] = x[670]&x[669];//
	count_nodes_vector.push_back(x[668]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(668);
	
	std::cerr<<"procesing gate 643..."<<std::endl;
	x[643] = (!x[156]|x[118])&(!x[118]|x[156]);// and (not _id_117 or _id_83) and (not _id_83 or _id_117) 
	count_nodes_vector.push_back(x[643]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(643);
	std::cerr<<"procesing gate 642..."<<std::endl;
	x[642] = x[644]&x[666]&x[668]&x[643];//
	count_nodes_vector.push_back(x[642]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(642);
	
	std::cerr<<"procesing gate 567..."<<std::endl;
	x[567] = (!x[118]|x[112])&(!x[112]|x[118]);// and (not _id_83 or buy_paths) and (not buy_paths or _id_83) 
	count_nodes_vector.push_back(x[567]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(567);
	std::cerr<<"procesing gate 566..."<<std::endl;
	x[566] = x[568]&x[580]&x[592]&x[642]&x[567];//
	count_nodes_vector.push_back(x[566]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(566);
			
	std::cerr<<"procesing gate 690..."<<std::endl;
	x[690] = (!x[180]|x[178]);// and (not _id_141 or _id_139) 
	count_nodes_vector.push_back(x[690]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(690);
	
	std::cerr<<"procesing gate 692..."<<std::endl;
	x[692] = (!x[181]|x[178]);// and (not _id_142 or _id_139) 
	count_nodes_vector.push_back(x[692]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(692);
	
	std::cerr<<"procesing gate 694..."<<std::endl;
	x[694] = (!x[182]|x[178]);// and (not _id_143 or _id_139) 
	count_nodes_vector.push_back(x[694]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(694);
	
	std::cerr<<"procesing gate 696..."<<std::endl;
	x[696] = (!x[183]|x[178]);// and (not _id_144 or _id_139) 
	count_nodes_vector.push_back(x[696]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(696);
	
	std::cerr<<"procesing gate 689..."<<std::endl;
	x[689] = (!x[178]|(x[180]|x[181]|x[182]|x[183]));// and (not _id_139 or (_id_141 or _id_142 or _id_143 or _id_144)) 
	count_nodes_vector.push_back(x[689]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(689);
	std::cerr<<"procesing gate 688..."<<std::endl;
	x[688] = x[690]&x[692]&x[694]&x[696]&x[689];//
	count_nodes_vector.push_back(x[688]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(688);
	
	std::cerr<<"procesing gate 687..."<<std::endl;
	x[687] = (!x[178]|x[112])&(!x[112]|x[178]);// and (not _id_139 or buy_paths) and (not buy_paths or _id_139) 
	count_nodes_vector.push_back(x[687]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(687);
	std::cerr<<"procesing gate 686..."<<std::endl;
	x[686] = x[688]&x[687];//
	count_nodes_vector.push_back(x[686]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(686);
			
	std::cerr<<"procesing gate 702..."<<std::endl;
	x[702] = (!x[186]|x[185])&(!x[185]|x[186]);// and (not buy_paths_288_289_290 or buy_paths_288_289) and (not buy_paths_288_289 or buy_paths_288_289_290) 
	count_nodes_vector.push_back(x[702]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(702);
	
	std::cerr<<"procesing gate 704..."<<std::endl;
	x[704] = (!x[187]|x[185]);// and (not buy_paths_288_289_291 or buy_paths_288_289) 
	count_nodes_vector.push_back(x[704]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(704);
	
	std::cerr<<"procesing gate 701..."<<std::endl;
	x[701] = (!x[185]|x[112]);// and (not buy_paths_288_289 or buy_paths) 
	count_nodes_vector.push_back(x[701]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(701);
	std::cerr<<"procesing gate 700..."<<std::endl;
	x[700] = x[702]&x[704]&x[701];//
	count_nodes_vector.push_back(x[700]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(700);
	
	std::cerr<<"procesing gate 699..."<<std::endl;
	x[699] = (!x[112]|(x[185]));// and (not buy_paths or (buy_paths_288_289)) 
	count_nodes_vector.push_back(x[699]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(699);
	std::cerr<<"procesing gate 698..."<<std::endl;
	x[698] = x[700]&x[699];//
	count_nodes_vector.push_back(x[698]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(698);
	
	std::cerr<<"procesing gate 555..."<<std::endl;
	x[555] = (!x[112]|x[1])&(!x[1]|x[112]);// and (not buy_paths or store_front) and (not store_front or buy_paths) 
	count_nodes_vector.push_back(x[555]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(555);
	std::cerr<<"procesing gate 554..."<<std::endl;
	x[554] = x[556]&x[566]&x[686]&x[698]&x[555];//
	count_nodes_vector.push_back(x[554]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(554);
				
	std::cerr<<"procesing gate 712..."<<std::endl;
	x[712] = (!x[191]|x[190]);// and (not _id_147 or _id_146) 
	count_nodes_vector.push_back(x[712]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(712);
	
	std::cerr<<"procesing gate 711..."<<std::endl;
	x[711] = (!x[190]|x[188]);// and (not _id_146 or customer_service) 
	count_nodes_vector.push_back(x[711]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(711);
	std::cerr<<"procesing gate 710..."<<std::endl;
	x[710] = x[712]&x[711];//
	count_nodes_vector.push_back(x[710]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(710);
	
	std::cerr<<"procesing gate 714..."<<std::endl;
	x[714] = (!x[192]|x[188]);// and (not _id_148 or customer_service) 
	count_nodes_vector.push_back(x[714]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(714);
				
	std::cerr<<"procesing gate 722..."<<std::endl;
	x[722] = (!x[196]|x[194]);// and (not _id_152 or _id_150) 
	count_nodes_vector.push_back(x[722]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(722);
	
	std::cerr<<"procesing gate 724..."<<std::endl;
	x[724] = (!x[197]|x[194]);// and (not _id_153 or _id_150) 
	count_nodes_vector.push_back(x[724]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(724);
	
	std::cerr<<"procesing gate 726..."<<std::endl;
	x[726] = (!x[198]|x[194]);// and (not _id_154 or _id_150) 
	count_nodes_vector.push_back(x[726]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(726);
	
	std::cerr<<"procesing gate 721..."<<std::endl;
	x[721] = (!x[194]|(x[196]|x[197]|x[198]));// and (not _id_150 or (_id_152 or _id_153 or _id_154)) 
	count_nodes_vector.push_back(x[721]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(721);
	std::cerr<<"procesing gate 720..."<<std::endl;
	x[720] = x[722]&x[724]&x[726]&x[721];//
	count_nodes_vector.push_back(x[720]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(720);
	
	std::cerr<<"procesing gate 719..."<<std::endl;
	x[719] = (!x[194]|x[193])&(!x[193]|x[194]);// and (not _id_150 or _id_149) and (not _id_149 or _id_150) 
	count_nodes_vector.push_back(x[719]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(719);
	std::cerr<<"procesing gate 718..."<<std::endl;
	x[718] = x[720]&x[719];//
	count_nodes_vector.push_back(x[718]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(718);
	
	std::cerr<<"procesing gate 728..."<<std::endl;
	x[728] = (!x[199]|x[193]);// and (not _id_155 or _id_149) 
	count_nodes_vector.push_back(x[728]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(728);
	
	std::cerr<<"procesing gate 717..."<<std::endl;
	x[717] = (!x[193]|x[188]);// and (not _id_149 or customer_service) 
	count_nodes_vector.push_back(x[717]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(717);
	std::cerr<<"procesing gate 716..."<<std::endl;
	x[716] = x[718]&x[728]&x[717];//
	count_nodes_vector.push_back(x[716]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(716);
			
	std::cerr<<"procesing gate 734..."<<std::endl;
	x[734] = (!x[202]|x[200]);// and (not _id_158 or _id_156) 
	count_nodes_vector.push_back(x[734]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(734);
	
	std::cerr<<"procesing gate 736..."<<std::endl;
	x[736] = (!x[203]|x[200]);// and (not _id_159 or _id_156) 
	count_nodes_vector.push_back(x[736]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(736);
	
	std::cerr<<"procesing gate 733..."<<std::endl;
	x[733] = (!x[200]|(x[202]|x[203]));// and (not _id_156 or (_id_158 or _id_159)) 
	count_nodes_vector.push_back(x[733]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(733);
	std::cerr<<"procesing gate 732..."<<std::endl;
	x[732] = x[734]&x[736]&x[733];//
	count_nodes_vector.push_back(x[732]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(732);
	
	std::cerr<<"procesing gate 731..."<<std::endl;
	x[731] = (!x[200]|x[188]);// and (not _id_156 or customer_service) 
	count_nodes_vector.push_back(x[731]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(731);
	std::cerr<<"procesing gate 730..."<<std::endl;
	x[730] = x[732]&x[731];//
	count_nodes_vector.push_back(x[730]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(730);
	
	std::cerr<<"procesing gate 709..."<<std::endl;
	x[709] = (!x[188]|(x[190]|x[192]|x[193]|x[200]));// and (not customer_service or (_id_146 or _id_148 or _id_149 or _id_156)) 
	count_nodes_vector.push_back(x[709]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(709);
	std::cerr<<"procesing gate 708..."<<std::endl;
	x[708] = x[710]&x[714]&x[716]&x[730]&x[709];//
	count_nodes_vector.push_back(x[708]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(708);
	
	std::cerr<<"procesing gate 707..."<<std::endl;
	x[707] = (!x[188]|x[1]);// and (not customer_service or store_front) 
	count_nodes_vector.push_back(x[707]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(707);
	std::cerr<<"procesing gate 706..."<<std::endl;
	x[706] = x[708]&x[707];//
	count_nodes_vector.push_back(x[706]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(706);
				
	std::cerr<<"procesing gate 744..."<<std::endl;
	x[744] = (!x[207]|x[205]);// and (not locally_visited_pages or _id_160) 
	count_nodes_vector.push_back(x[744]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(744);
	
	std::cerr<<"procesing gate 746..."<<std::endl;
	x[746] = (!x[208]|x[205]);// and (not external_referring_pages or _id_160) 
	count_nodes_vector.push_back(x[746]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(746);
	
	std::cerr<<"procesing gate 748..."<<std::endl;
	x[748] = (!x[209]|x[205]);// and (not behaviour_tracked_previous_purchases or _id_160) 
	count_nodes_vector.push_back(x[748]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(748);
	
	std::cerr<<"procesing gate 743..."<<std::endl;
	x[743] = (!x[205]|(x[207]|x[208]|x[209]));// and (not _id_160 or (locally_visited_pages or external_referring_pages or behaviour_tracked_previous_purchases)) 
	count_nodes_vector.push_back(x[743]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(743);
	std::cerr<<"procesing gate 742..."<<std::endl;
	x[742] = x[744]&x[746]&x[748]&x[743];//
	count_nodes_vector.push_back(x[742]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(742);
	
	std::cerr<<"procesing gate 741..."<<std::endl;
	x[741] = (!x[205]|x[204])&(!x[204]|x[205]);// and (not _id_160 or user_behaviour_tracking) and (not user_behaviour_tracking or _id_160) 
	count_nodes_vector.push_back(x[741]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(741);
	std::cerr<<"procesing gate 740..."<<std::endl;
	x[740] = x[742]&x[741];//
	count_nodes_vector.push_back(x[740]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(740);
	
	std::cerr<<"procesing gate 739..."<<std::endl;
	x[739] = (!x[204]|x[1]);// and (not user_behaviour_tracking or store_front) 
	count_nodes_vector.push_back(x[739]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(739);
	std::cerr<<"procesing gate 738..."<<std::endl;
	x[738] = x[740]&x[739];//
	count_nodes_vector.push_back(x[738]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(738);
	
	std::cerr<<"procesing gate 333..."<<std::endl;
	x[333] = (!x[1]|x[0])&(!x[0]|x[1]);// and (not store_front or eShop) and (not eShop or store_front) 
	count_nodes_vector.push_back(x[333]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(333);
	std::cerr<<"procesing gate 332..."<<std::endl;
	x[332] = x[334]&x[358]&x[424]&x[536]&x[554]&x[706]&x[738]&x[333];//
	count_nodes_vector.push_back(x[332]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(332);
						
	std::cerr<<"procesing gate 760..."<<std::endl;
	x[760] = (!x[215]|x[214])&(!x[214]|x[215]);// and (not warehouse_management or physical_goods_fulfillment) and (not physical_goods_fulfillment or warehouse_management) 
	count_nodes_vector.push_back(x[760]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(760);
					
	std::cerr<<"procesing gate 770..."<<std::endl;
	x[770] = (!x[220]|x[219])&(!x[219]|x[220]);// and (not _id_168 or _id_167) and (not _id_167 or _id_168) 
	count_nodes_vector.push_back(x[770]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(770);
			
	std::cerr<<"procesing gate 776..."<<std::endl;
	x[776] = (!x[223]|x[221]);// and (not _id_171 or _id_169) 
	count_nodes_vector.push_back(x[776]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(776);
	
	std::cerr<<"procesing gate 778..."<<std::endl;
	x[778] = (!x[224]|x[221]);// and (not _id_172 or _id_169) 
	count_nodes_vector.push_back(x[778]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(778);
	
	std::cerr<<"procesing gate 780..."<<std::endl;
	x[780] = (!x[225]|x[221]);// and (not _id_173 or _id_169) 
	count_nodes_vector.push_back(x[780]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(780);
	
	std::cerr<<"procesing gate 782..."<<std::endl;
	x[782] = (!x[226]|x[221]);// and (not _id_174 or _id_169) 
	count_nodes_vector.push_back(x[782]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(782);
	
	std::cerr<<"procesing gate 775..."<<std::endl;
	x[775] = (!x[221]|(x[223]|x[224]|x[225]|x[226]));// and (not _id_169 or (_id_171 or _id_172 or _id_173 or _id_174)) 
	count_nodes_vector.push_back(x[775]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(775);
	std::cerr<<"procesing gate 774..."<<std::endl;
	x[774] = x[776]&x[778]&x[780]&x[782]&x[775];//
	count_nodes_vector.push_back(x[774]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(774);
	
	std::cerr<<"procesing gate 773..."<<std::endl;
	x[773] = (!x[221]|x[219]);// and (not _id_169 or _id_167) 
	count_nodes_vector.push_back(x[773]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(773);
	std::cerr<<"procesing gate 772..."<<std::endl;
	x[772] = x[774]&x[773];//
	count_nodes_vector.push_back(x[772]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(772);
	
	std::cerr<<"procesing gate 769..."<<std::endl;
	x[769] = (!x[219]|x[218])&(!x[218]|x[219]);// and (not _id_167 or _id_166) and (not _id_166 or _id_167) 
	count_nodes_vector.push_back(x[769]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(769);
	std::cerr<<"procesing gate 768..."<<std::endl;
	x[768] = x[770]&x[772]&x[769];//
	count_nodes_vector.push_back(x[768]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(768);
	
	std::cerr<<"procesing gate 767..."<<std::endl;
	x[767] = (!x[218]|x[216]);// and (not _id_166 or shipping) 
	count_nodes_vector.push_back(x[767]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(767);
	std::cerr<<"procesing gate 766..."<<std::endl;
	x[766] = x[768]&x[767];//
	count_nodes_vector.push_back(x[766]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(766);
			
	std::cerr<<"procesing gate 788..."<<std::endl;
	x[788] = (!x[229]|x[227]);// and (not _id_177 or _id_175) 
	count_nodes_vector.push_back(x[788]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(788);
	
	std::cerr<<"procesing gate 790..."<<std::endl;
	x[790] = (!x[230]|x[227]);// and (not _id_178 or _id_175) 
	count_nodes_vector.push_back(x[790]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(790);
	
	std::cerr<<"procesing gate 792..."<<std::endl;
	x[792] = (!x[231]|x[227]);// and (not _id_179 or _id_175) 
	count_nodes_vector.push_back(x[792]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(792);
	
	std::cerr<<"procesing gate 794..."<<std::endl;
	x[794] = (!x[232]|x[227]);// and (not _id_180 or _id_175) 
	count_nodes_vector.push_back(x[794]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(794);
	
	std::cerr<<"procesing gate 796..."<<std::endl;
	x[796] = (!x[233]|x[227]);// and (not _id_181 or _id_175) 
	count_nodes_vector.push_back(x[796]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(796);
	
	std::cerr<<"procesing gate 787..."<<std::endl;
	x[787] = (!x[227]|(x[229]|x[230]|x[231]|x[232]|x[233]));// and (not _id_175 or (_id_177 or _id_178 or _id_179 or _id_180 or _id_181)) 
	count_nodes_vector.push_back(x[787]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(787);
	std::cerr<<"procesing gate 786..."<<std::endl;
	x[786] = x[788]&x[790]&x[792]&x[794]&x[796]&x[787];//
	count_nodes_vector.push_back(x[786]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(786);
	
	std::cerr<<"procesing gate 785..."<<std::endl;
	x[785] = (!x[227]|x[216]);// and (not _id_175 or shipping) 
	count_nodes_vector.push_back(x[785]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(785);
	std::cerr<<"procesing gate 784..."<<std::endl;
	x[784] = x[786]&x[785];//
	count_nodes_vector.push_back(x[784]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(784);
	
	std::cerr<<"procesing gate 765..."<<std::endl;
	x[765] = (!x[216]|(x[218]|x[227]));// and (not shipping or (_id_166 or _id_175)) 
	count_nodes_vector.push_back(x[765]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(765);
	std::cerr<<"procesing gate 764..."<<std::endl;
	x[764] = x[766]&x[784]&x[765];//
	count_nodes_vector.push_back(x[764]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(764);
	
	std::cerr<<"procesing gate 763..."<<std::endl;
	x[763] = (!x[216]|x[214])&(!x[214]|x[216]);// and (not shipping or physical_goods_fulfillment) and (not physical_goods_fulfillment or shipping) 
	count_nodes_vector.push_back(x[763]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(763);
	std::cerr<<"procesing gate 762..."<<std::endl;
	x[762] = x[764]&x[763];//
	count_nodes_vector.push_back(x[762]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(762);
	
	std::cerr<<"procesing gate 759..."<<std::endl;
	x[759] = (!x[214]|x[212]);// and (not physical_goods_fulfillment or _id_163) 
	count_nodes_vector.push_back(x[759]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(759);
	std::cerr<<"procesing gate 758..."<<std::endl;
	x[758] = x[760]&x[762]&x[759];//
	count_nodes_vector.push_back(x[758]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(758);
		
	std::cerr<<"procesing gate 800..."<<std::endl;
	x[800] = (!x[235]|x[234])&(!x[234]|x[235]);// and (not _id_182 or eletronic_goods_fulfillment) and (not eletronic_goods_fulfillment or _id_182) 
	count_nodes_vector.push_back(x[800]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(800);
	
	std::cerr<<"procesing gate 802..."<<std::endl;
	x[802] = (!x[236]|x[234])&(!x[234]|x[236]);// and (not _id_183 or eletronic_goods_fulfillment) and (not eletronic_goods_fulfillment or _id_183) 
	count_nodes_vector.push_back(x[802]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(802);
	
	std::cerr<<"procesing gate 799..."<<std::endl;
	x[799] = (!x[234]|x[212]);// and (not eletronic_goods_fulfillment or _id_163) 
	count_nodes_vector.push_back(x[799]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(799);
	std::cerr<<"procesing gate 798..."<<std::endl;
	x[798] = x[800]&x[802]&x[799];//
	count_nodes_vector.push_back(x[798]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(798);
		
	std::cerr<<"procesing gate 806..."<<std::endl;
	x[806] = (!x[238]|x[237]);// and (not _id_184 or services_fulfillment) 
	count_nodes_vector.push_back(x[806]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(806);
	
	std::cerr<<"procesing gate 808..."<<std::endl;
	x[808] = (!x[239]|x[237]);// and (not _id_185 or services_fulfillment) 
	count_nodes_vector.push_back(x[808]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(808);
	
	std::cerr<<"procesing gate 805..."<<std::endl;
	x[805] = (!x[237]|x[212]);// and (not services_fulfillment or _id_163) 
	count_nodes_vector.push_back(x[805]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(805);
	std::cerr<<"procesing gate 804..."<<std::endl;
	x[804] = x[806]&x[808]&x[805];//
	count_nodes_vector.push_back(x[804]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(804);
	
	std::cerr<<"procesing gate 757..."<<std::endl;
	x[757] = (!x[212]|(x[214]|x[234]|x[237]));// and (not _id_163 or (physical_goods_fulfillment or eletronic_goods_fulfillment or services_fulfillment)) 
	count_nodes_vector.push_back(x[757]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(757);
	std::cerr<<"procesing gate 756..."<<std::endl;
	x[756] = x[758]&x[798]&x[804]&x[757];//
	count_nodes_vector.push_back(x[756]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(756);
	
	std::cerr<<"procesing gate 755..."<<std::endl;
	x[755] = (!x[212]|x[211])&(!x[211]|x[212]);// and (not _id_163 or _id_162) and (not _id_162 or _id_163) 
	count_nodes_vector.push_back(x[755]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(755);
	std::cerr<<"procesing gate 754..."<<std::endl;
	x[754] = x[756]&x[755];//
	count_nodes_vector.push_back(x[754]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(754);
	
	std::cerr<<"procesing gate 753..."<<std::endl;
	x[753] = (!x[211]|x[210])&(!x[210]|x[211]);// and (not _id_162 or business_management) and (not business_management or _id_162) 
	count_nodes_vector.push_back(x[753]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(753);
	std::cerr<<"procesing gate 752..."<<std::endl;
	x[752] = x[754]&x[753];//
	count_nodes_vector.push_back(x[752]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(752);
				
	std::cerr<<"procesing gate 816..."<<std::endl;
	x[816] = (!x[243]|x[241]);// and (not customer_preferences or _id_187) 
	count_nodes_vector.push_back(x[816]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(816);
	
	std::cerr<<"procesing gate 818..."<<std::endl;
	x[818] = (!x[244]|x[241]);// and (not _id_189 or _id_187) 
	count_nodes_vector.push_back(x[818]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(818);
	
	std::cerr<<"procesing gate 820..."<<std::endl;
	x[820] = (!x[245]|x[241]);// and (not _id_190 or _id_187) 
	count_nodes_vector.push_back(x[820]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(820);
	
	std::cerr<<"procesing gate 822..."<<std::endl;
	x[822] = (!x[246]|x[241]);// and (not targeting_criteria_previous_purchases or _id_187) 
	count_nodes_vector.push_back(x[822]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(822);
	
	std::cerr<<"procesing gate 824..."<<std::endl;
	x[824] = (!x[247]|x[241]);// and (not _id_191 or _id_187) 
	count_nodes_vector.push_back(x[824]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(824);
	
	std::cerr<<"procesing gate 826..."<<std::endl;
	x[826] = (!x[248]|x[241]);// and (not wish_list_content or _id_187) 
	count_nodes_vector.push_back(x[826]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(826);
	
	std::cerr<<"procesing gate 828..."<<std::endl;
	x[828] = (!x[249]|x[241]);// and (not previously_visited_pages or _id_187) 
	count_nodes_vector.push_back(x[828]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(828);
	
	std::cerr<<"procesing gate 830..."<<std::endl;
	x[830] = (!x[250]|x[241]);// and (not _id_192 or _id_187) 
	count_nodes_vector.push_back(x[830]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(830);
	
	std::cerr<<"procesing gate 832..."<<std::endl;
	x[832] = (!x[251]|x[241]);// and (not _id_193 or _id_187) 
	count_nodes_vector.push_back(x[832]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(832);
	
	std::cerr<<"procesing gate 815..."<<std::endl;
	x[815] = (!x[241]|(x[243]|x[244]|x[245]|x[246]|x[247]|x[248]|x[249]|x[250]|x[251]));// and (not _id_187 or (customer_preferences or _id_189 or _id_190 or targeting_criteria_previous_purchases or _id_191 or wish_list_content or previously_visited_pages or _id_192 or _id_193)) 
	count_nodes_vector.push_back(x[815]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(815);
	std::cerr<<"procesing gate 814..."<<std::endl;
	x[814] = x[816]&x[818]&x[820]&x[822]&x[824]&x[826]&x[828]&x[830]&x[832]&x[815];//
	count_nodes_vector.push_back(x[814]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(814);
	
	std::cerr<<"procesing gate 813..."<<std::endl;
	x[813] = (!x[241]|x[240])&(!x[240]|x[241]);// and (not _id_187 or _id_186) and (not _id_186 or _id_187) 
	count_nodes_vector.push_back(x[813]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(813);
	std::cerr<<"procesing gate 812..."<<std::endl;
	x[812] = x[814]&x[813];//
	count_nodes_vector.push_back(x[812]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(812);
						
	std::cerr<<"procesing gate 844..."<<std::endl;
	x[844] = (!x[257]|x[255]);// and (not _id_199 or _id_197) 
	count_nodes_vector.push_back(x[844]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(844);
	
	std::cerr<<"procesing gate 846..."<<std::endl;
	x[846] = (!x[258]|x[255]);// and (not _id_200 or _id_197) 
	count_nodes_vector.push_back(x[846]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(846);
	
	std::cerr<<"procesing gate 843..."<<std::endl;
	x[843] = (!x[255]|(x[257]|x[258]));// and (not _id_197 or (_id_199 or _id_200)) 
	count_nodes_vector.push_back(x[843]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(843);
	std::cerr<<"procesing gate 842..."<<std::endl;
	x[842] = x[844]&x[846]&x[843];//
	count_nodes_vector.push_back(x[842]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(842);
	
	std::cerr<<"procesing gate 841..."<<std::endl;
	x[841] = (!x[255]|x[254])&(!x[254]|x[255]);// and (not _id_197 or _id_196) and (not _id_196 or _id_197) 
	count_nodes_vector.push_back(x[841]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(841);
	std::cerr<<"procesing gate 840..."<<std::endl;
	x[840] = x[842]&x[841];//
	count_nodes_vector.push_back(x[840]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(840);
			
	std::cerr<<"procesing gate 852..."<<std::endl;
	x[852] = (!x[261]|x[259]);// and (not _id_203 or _id_201) 
	count_nodes_vector.push_back(x[852]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(852);
		
	std::cerr<<"procesing gate 856..."<<std::endl;
	x[856] = (!x[263]|x[262])&(!x[262]|x[263]);// and (not _id_205 or _id_204) and (not _id_204 or _id_205) 
	count_nodes_vector.push_back(x[856]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(856);
	
	std::cerr<<"procesing gate 855..."<<std::endl;
	x[855] = (!x[262]|x[259]);// and (not _id_204 or _id_201) 
	count_nodes_vector.push_back(x[855]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(855);
	std::cerr<<"procesing gate 854..."<<std::endl;
	x[854] = x[856]&x[855];//
	count_nodes_vector.push_back(x[854]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(854);
	
	std::cerr<<"procesing gate 851..."<<std::endl;
	x[851] = (!x[259]|(x[261]|x[262]));// and (not _id_201 or (_id_203 or _id_204)) 
	count_nodes_vector.push_back(x[851]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(851);
	std::cerr<<"procesing gate 850..."<<std::endl;
	x[850] = x[852]&x[854]&x[851];//
	count_nodes_vector.push_back(x[850]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(850);
	
	std::cerr<<"procesing gate 849..."<<std::endl;
	x[849] = (!x[259]|x[254])&(!x[254]|x[259]);// and (not _id_201 or _id_196) and (not _id_196 or _id_201) 
	count_nodes_vector.push_back(x[849]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(849);
	std::cerr<<"procesing gate 848..."<<std::endl;
	x[848] = x[850]&x[849];//
	count_nodes_vector.push_back(x[848]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(848);
	
	std::cerr<<"procesing gate 858..."<<std::endl;
	x[858] = (!x[264]|x[254]);// and (not _id_206 or _id_196) 
	count_nodes_vector.push_back(x[858]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(858);
	
	std::cerr<<"procesing gate 860..."<<std::endl;
	x[860] = (!x[265]|x[254]);// and (not _id_207 or _id_196) 
	count_nodes_vector.push_back(x[860]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(860);
	
	std::cerr<<"procesing gate 839..."<<std::endl;
	x[839] = (!x[254]|x[252]);// and (not _id_196 or _id_194) 
	count_nodes_vector.push_back(x[839]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(839);
	std::cerr<<"procesing gate 838..."<<std::endl;
	x[838] = x[840]&x[848]&x[858]&x[860]&x[839];//
	count_nodes_vector.push_back(x[838]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(838);
			
	std::cerr<<"procesing gate 866..."<<std::endl;
	x[866] = (!x[268]|x[267])&(!x[267]|x[268]);// and (not _id_209 or _id_208) and (not _id_208 or _id_209) 
	count_nodes_vector.push_back(x[866]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(866);
	
	std::cerr<<"procesing gate 868..."<<std::endl;
	x[868] = (!x[269]|x[267])&(!x[267]|x[269]);// and (not _id_210 or _id_208) and (not _id_208 or _id_210) 
	count_nodes_vector.push_back(x[868]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(868);
	
	std::cerr<<"procesing gate 870..."<<std::endl;
	x[870] = (!x[270]|x[267]);// and (not _id_211 or _id_208) 
	count_nodes_vector.push_back(x[870]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(870);
	
	std::cerr<<"procesing gate 865..."<<std::endl;
	x[865] = (!x[267]|x[266])&(!x[266]|x[267]);// and (not _id_208 or discounts) and (not discounts or _id_208) 
	count_nodes_vector.push_back(x[865]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(865);
	std::cerr<<"procesing gate 864..."<<std::endl;
	x[864] = x[866]&x[868]&x[870]&x[865];//
	count_nodes_vector.push_back(x[864]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(864);
			
	std::cerr<<"procesing gate 876..."<<std::endl;
	x[876] = (!x[273]|x[271]);// and (not _id_214 or _id_212) 
	count_nodes_vector.push_back(x[876]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(876);
	
	std::cerr<<"procesing gate 878..."<<std::endl;
	x[878] = (!x[274]|x[271]);// and (not _id_215 or _id_212) 
	count_nodes_vector.push_back(x[878]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(878);
	
	std::cerr<<"procesing gate 880..."<<std::endl;
	x[880] = (!x[275]|x[271]);// and (not _id_216 or _id_212) 
	count_nodes_vector.push_back(x[880]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(880);
	
	std::cerr<<"procesing gate 875..."<<std::endl;
	x[875] = (!x[271]|(x[273]|x[274]|x[275]));// and (not _id_212 or (_id_214 or _id_215 or _id_216)) 
	count_nodes_vector.push_back(x[875]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(875);
	std::cerr<<"procesing gate 874..."<<std::endl;
	x[874] = x[876]&x[878]&x[880]&x[875];//
	count_nodes_vector.push_back(x[874]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(874);
	
	std::cerr<<"procesing gate 873..."<<std::endl;
	x[873] = (!x[271]|x[266])&(!x[266]|x[271]);// and (not _id_212 or discounts) and (not discounts or _id_212) 
	count_nodes_vector.push_back(x[873]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(873);
	std::cerr<<"procesing gate 872..."<<std::endl;
	x[872] = x[874]&x[873];//
	count_nodes_vector.push_back(x[872]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(872);
		
	std::cerr<<"procesing gate 884..."<<std::endl;
	x[884] = (!x[277]|x[276]);// and (not _id_218 or _id_217) 
	count_nodes_vector.push_back(x[884]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(884);
	
	std::cerr<<"procesing gate 886..."<<std::endl;
	x[886] = (!x[278]|x[276]);// and (not _id_219 or _id_217) 
	count_nodes_vector.push_back(x[886]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(886);
	
	std::cerr<<"procesing gate 883..."<<std::endl;
	x[883] = (!x[276]|x[266])&(!x[266]|x[276]);// and (not _id_217 or discounts) and (not discounts or _id_217) 
	count_nodes_vector.push_back(x[883]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(883);
	std::cerr<<"procesing gate 882..."<<std::endl;
	x[882] = x[884]&x[886]&x[883];//
	count_nodes_vector.push_back(x[882]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(882);
			
	std::cerr<<"procesing gate 892..."<<std::endl;
	x[892] = (!x[281]|x[279]);// and (not _id_222 or _id_220) 
	count_nodes_vector.push_back(x[892]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(892);
	
	std::cerr<<"procesing gate 894..."<<std::endl;
	x[894] = (!x[282]|x[279]);// and (not _id_223 or _id_220) 
	count_nodes_vector.push_back(x[894]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(894);
	
	std::cerr<<"procesing gate 891..."<<std::endl;
	x[891] = (!x[279]|(x[281]|x[282]));// and (not _id_220 or (_id_222 or _id_223)) 
	count_nodes_vector.push_back(x[891]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(891);
	std::cerr<<"procesing gate 890..."<<std::endl;
	x[890] = x[892]&x[894]&x[891];//
	count_nodes_vector.push_back(x[890]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(890);
	
	std::cerr<<"procesing gate 889..."<<std::endl;
	x[889] = (!x[279]|x[266])&(!x[266]|x[279]);// and (not _id_220 or discounts) and (not discounts or _id_220) 
	count_nodes_vector.push_back(x[889]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(889);
	std::cerr<<"procesing gate 888..."<<std::endl;
	x[888] = x[890]&x[889];//
	count_nodes_vector.push_back(x[888]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(888);
	
	std::cerr<<"procesing gate 896..."<<std::endl;
	x[896] = (!x[283]|x[266]);// and (not _id_224 or discounts) 
	count_nodes_vector.push_back(x[896]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(896);
	
	std::cerr<<"procesing gate 898..."<<std::endl;
	x[898] = (!x[284]|x[266])&(!x[266]|x[284]);// and (not _id_225 or discounts) and (not discounts or _id_225) 
	count_nodes_vector.push_back(x[898]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(898);
	
	std::cerr<<"procesing gate 863..."<<std::endl;
	x[863] = (!x[266]|x[252]);// and (not discounts or _id_194) 
	count_nodes_vector.push_back(x[863]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(863);
	std::cerr<<"procesing gate 862..."<<std::endl;
	x[862] = x[864]&x[872]&x[882]&x[888]&x[896]&x[898]&x[863];//
	count_nodes_vector.push_back(x[862]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(862);
			
	std::cerr<<"procesing gate 904..."<<std::endl;
	x[904] = (!x[287]|x[285]);// and (not _id_228 or _id_226) 
	count_nodes_vector.push_back(x[904]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(904);
		
	std::cerr<<"procesing gate 908..."<<std::endl;
	x[908] = (!x[289]|x[288])&(!x[288]|x[289]);// and (not _id_230 or _id_229) and (not _id_229 or _id_230) 
	count_nodes_vector.push_back(x[908]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(908);
	
	std::cerr<<"procesing gate 907..."<<std::endl;
	x[907] = (!x[288]|x[285]);// and (not _id_229 or _id_226) 
	count_nodes_vector.push_back(x[907]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(907);
	std::cerr<<"procesing gate 906..."<<std::endl;
	x[906] = x[908]&x[907];//
	count_nodes_vector.push_back(x[906]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(906);
		
	std::cerr<<"procesing gate 912..."<<std::endl;
	x[912] = (!x[291]|x[290])&(!x[290]|x[291]);// and (not _id_232 or _id_231) and (not _id_231 or _id_232) 
	count_nodes_vector.push_back(x[912]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(912);
	
	std::cerr<<"procesing gate 911..."<<std::endl;
	x[911] = (!x[290]|x[285]);// and (not _id_231 or _id_226) 
	count_nodes_vector.push_back(x[911]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(911);
	std::cerr<<"procesing gate 910..."<<std::endl;
	x[910] = x[912]&x[911];//
	count_nodes_vector.push_back(x[910]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(910);
	
	std::cerr<<"procesing gate 903..."<<std::endl;
	x[903] = (!x[285]|(x[287]|x[288]|x[290]));// and (not _id_226 or (_id_228 or _id_229 or _id_231)) 
	count_nodes_vector.push_back(x[903]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(903);
	std::cerr<<"procesing gate 902..."<<std::endl;
	x[902] = x[904]&x[906]&x[910]&x[903];//
	count_nodes_vector.push_back(x[902]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(902);
	
	std::cerr<<"procesing gate 901..."<<std::endl;
	x[901] = (!x[285]|x[252]);// and (not _id_226 or _id_194) 
	count_nodes_vector.push_back(x[901]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(901);
	std::cerr<<"procesing gate 900..."<<std::endl;
	x[900] = x[902]&x[901];//
	count_nodes_vector.push_back(x[900]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(900);
	
	std::cerr<<"procesing gate 837..."<<std::endl;
	x[837] = (!x[252]|(x[254]|x[266]|x[285]));// and (not _id_194 or (_id_196 or discounts or _id_226)) 
	count_nodes_vector.push_back(x[837]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(837);
	std::cerr<<"procesing gate 836..."<<std::endl;
	x[836] = x[838]&x[862]&x[900]&x[837];//
	count_nodes_vector.push_back(x[836]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(836);
	
	std::cerr<<"procesing gate 835..."<<std::endl;
	x[835] = (!x[252]|x[240])&(!x[240]|x[252]);// and (not _id_194 or _id_186) and (not _id_186 or _id_194) 
	count_nodes_vector.push_back(x[835]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(835);
	std::cerr<<"procesing gate 834..."<<std::endl;
	x[834] = x[836]&x[835];//
	count_nodes_vector.push_back(x[834]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(834);
			
	std::cerr<<"procesing gate 918..."<<std::endl;
	x[918] = (!x[294]|x[292]);// and (not _id_235 or _id_233) 
	count_nodes_vector.push_back(x[918]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(918);
	
	std::cerr<<"procesing gate 920..."<<std::endl;
	x[920] = (!x[295]|x[292]);// and (not _id_236 or _id_233) 
	count_nodes_vector.push_back(x[920]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(920);
		
	std::cerr<<"procesing gate 924..."<<std::endl;
	x[924] = (!x[297]|x[296]);// and (not personalized_emails or _id_237) 
	count_nodes_vector.push_back(x[924]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(924);
	
	std::cerr<<"procesing gate 926..."<<std::endl;
	x[926] = (!x[298]|x[296]);// and (not _id_238 or _id_237) 
	count_nodes_vector.push_back(x[926]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(926);
	
	std::cerr<<"procesing gate 923..."<<std::endl;
	x[923] = (!x[296]|x[292]);// and (not _id_237 or _id_233) 
	count_nodes_vector.push_back(x[923]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(923);
	std::cerr<<"procesing gate 922..."<<std::endl;
	x[922] = x[924]&x[926]&x[923];//
	count_nodes_vector.push_back(x[922]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(922);
	
	std::cerr<<"procesing gate 917..."<<std::endl;
	x[917] = (!x[292]|(x[294]|x[295]|x[296]));// and (not _id_233 or (_id_235 or _id_236 or _id_237)) 
	count_nodes_vector.push_back(x[917]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(917);
	std::cerr<<"procesing gate 916..."<<std::endl;
	x[916] = x[918]&x[920]&x[922]&x[917];//
	count_nodes_vector.push_back(x[916]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(916);
	
	std::cerr<<"procesing gate 915..."<<std::endl;
	x[915] = (!x[292]|x[240])&(!x[240]|x[292]);// and (not _id_233 or _id_186) and (not _id_186 or _id_233) 
	count_nodes_vector.push_back(x[915]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(915);
	std::cerr<<"procesing gate 914..."<<std::endl;
	x[914] = x[916]&x[915];//
	count_nodes_vector.push_back(x[914]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(914);
	
	std::cerr<<"procesing gate 928..."<<std::endl;
	x[928] = (!x[299]|x[240]);// and (not _id_239 or _id_186) 
	count_nodes_vector.push_back(x[928]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(928);
	
	std::cerr<<"procesing gate 811..."<<std::endl;
	x[811] = (!x[240]|x[210]);// and (not _id_186 or business_management) 
	count_nodes_vector.push_back(x[811]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(811);
	std::cerr<<"procesing gate 810..."<<std::endl;
	x[810] = x[812]&x[834]&x[914]&x[928]&x[811];//
	count_nodes_vector.push_back(x[810]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(810);
		
	std::cerr<<"procesing gate 932..."<<std::endl;
	x[932] = (!x[301]|x[300])&(!x[300]|x[301]);// and (not _id_241 or _id_240) and (not _id_240 or _id_241) 
	count_nodes_vector.push_back(x[932]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(932);
	
	std::cerr<<"procesing gate 934..."<<std::endl;
	x[934] = (!x[302]|x[300])&(!x[300]|x[302]);// and (not _id_242 or _id_240) and (not _id_240 or _id_242) 
	count_nodes_vector.push_back(x[934]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(934);
	
	std::cerr<<"procesing gate 931..."<<std::endl;
	x[931] = (!x[300]|x[210]);// and (not _id_240 or business_management) 
	count_nodes_vector.push_back(x[931]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(931);
	std::cerr<<"procesing gate 930..."<<std::endl;
	x[930] = x[932]&x[934]&x[931];//
	count_nodes_vector.push_back(x[930]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(930);
		
	std::cerr<<"procesing gate 938..."<<std::endl;
	x[938] = (!x[304]|x[303]);// and (not _id_243 or inventory_tracking) 
	count_nodes_vector.push_back(x[938]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(938);
	
	std::cerr<<"procesing gate 937..."<<std::endl;
	x[937] = (!x[303]|x[210]);// and (not inventory_tracking or business_management) 
	count_nodes_vector.push_back(x[937]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(937);
	std::cerr<<"procesing gate 936..."<<std::endl;
	x[936] = x[938]&x[937];//
	count_nodes_vector.push_back(x[936]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(936);
			
	std::cerr<<"procesing gate 944..."<<std::endl;
	x[944] = (!x[307]|x[306])&(!x[306]|x[307]);// and (not _id_245 or _id_244) and (not _id_244 or _id_245) 
	count_nodes_vector.push_back(x[944]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(944);
		
	std::cerr<<"procesing gate 948..."<<std::endl;
	x[948] = (!x[309]|x[308])&(!x[308]|x[309]);// and (not _id_246 or automatic) and (not automatic or _id_246) 
	count_nodes_vector.push_back(x[948]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(948);
	
	std::cerr<<"procesing gate 947..."<<std::endl;
	x[947] = (!x[308]|x[306]);// and (not automatic or _id_244) 
	count_nodes_vector.push_back(x[947]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(947);
	std::cerr<<"procesing gate 946..."<<std::endl;
	x[946] = x[948]&x[947];//
	count_nodes_vector.push_back(x[946]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(946);
	
	std::cerr<<"procesing gate 943..."<<std::endl;
	x[943] = (!x[306]|x[305])&(!x[305]|x[306]);// and (not _id_244 or procurement) and (not procurement or _id_244) 
	count_nodes_vector.push_back(x[943]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(943);
	std::cerr<<"procesing gate 942..."<<std::endl;
	x[942] = x[944]&x[946]&x[943];//
	count_nodes_vector.push_back(x[942]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(942);
	
	std::cerr<<"procesing gate 941..."<<std::endl;
	x[941] = (!x[305]|x[210]);// and (not procurement or business_management) 
	count_nodes_vector.push_back(x[941]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(941);
	std::cerr<<"procesing gate 940..."<<std::endl;
	x[940] = x[942]&x[941];//
	count_nodes_vector.push_back(x[940]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(940);
		
	std::cerr<<"procesing gate 952..."<<std::endl;
	x[952] = (!x[311]|x[310])&(!x[310]|x[311]);// and (not _id_247 or reporting_and_analysis) and (not reporting_and_analysis or _id_247) 
	count_nodes_vector.push_back(x[952]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(952);
	
	std::cerr<<"procesing gate 954..."<<std::endl;
	x[954] = (!x[312]|x[310])&(!x[310]|x[312]);// and (not _id_248 or reporting_and_analysis) and (not reporting_and_analysis or _id_248) 
	count_nodes_vector.push_back(x[954]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(954);
	
	std::cerr<<"procesing gate 956..."<<std::endl;
	x[956] = (!x[313]|x[310])&(!x[310]|x[313]);// and (not _id_249 or reporting_and_analysis) and (not reporting_and_analysis or _id_249) 
	count_nodes_vector.push_back(x[956]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(956);
	
	std::cerr<<"procesing gate 951..."<<std::endl;
	x[951] = (!x[310]|x[210]);// and (not reporting_and_analysis or business_management) 
	count_nodes_vector.push_back(x[951]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(951);
	std::cerr<<"procesing gate 950..."<<std::endl;
	x[950] = x[952]&x[954]&x[956]&x[951];//
	count_nodes_vector.push_back(x[950]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(950);
			
	std::cerr<<"procesing gate 962..."<<std::endl;
	x[962] = (!x[316]|x[314]);// and (not fulfillment_system or _id_250) 
	count_nodes_vector.push_back(x[962]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(962);
	
	std::cerr<<"procesing gate 964..."<<std::endl;
	x[964] = (!x[317]|x[314]);// and (not _id_252 or _id_250) 
	count_nodes_vector.push_back(x[964]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(964);
	
	std::cerr<<"procesing gate 966..."<<std::endl;
	x[966] = (!x[318]|x[314]);// and (not procurement_system or _id_250) 
	count_nodes_vector.push_back(x[966]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(966);
	
	std::cerr<<"procesing gate 968..."<<std::endl;
	x[968] = (!x[319]|x[314]);// and (not _id_253 or _id_250) 
	count_nodes_vector.push_back(x[968]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(968);
	
	std::cerr<<"procesing gate 961..."<<std::endl;
	x[961] = (!x[314]|(x[316]|x[317]|x[318]|x[319]));// and (not _id_250 or (fulfillment_system or _id_252 or procurement_system or _id_253)) 
	count_nodes_vector.push_back(x[961]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(961);
	std::cerr<<"procesing gate 960..."<<std::endl;
	x[960] = x[962]&x[964]&x[966]&x[968]&x[961];//
	count_nodes_vector.push_back(x[960]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(960);
	
	std::cerr<<"procesing gate 959..."<<std::endl;
	x[959] = (!x[314]|x[210]);// and (not _id_250 or business_management) 
	count_nodes_vector.push_back(x[959]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(959);
	std::cerr<<"procesing gate 958..."<<std::endl;
	x[958] = x[960]&x[959];//
	count_nodes_vector.push_back(x[958]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(958);
			
	std::cerr<<"procesing gate 974..."<<std::endl;
	x[974] = (!x[322]|x[321])&(!x[321]|x[322]);// and (not _id_256 or _id_255) and (not _id_255 or _id_256) 
	count_nodes_vector.push_back(x[974]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(974);
	
	std::cerr<<"procesing gate 976..."<<std::endl;
	x[976] = (!x[323]|x[321])&(!x[321]|x[323]);// and (not _id_257 or _id_255) and (not _id_255 or _id_257) 
	count_nodes_vector.push_back(x[976]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(976);
	
	std::cerr<<"procesing gate 978..."<<std::endl;
	x[978] = (!x[324]|x[321])&(!x[321]|x[324]);// and (not _id_258 or _id_255) and (not _id_255 or _id_258) 
	count_nodes_vector.push_back(x[978]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(978);
	
	std::cerr<<"procesing gate 980..."<<std::endl;
	x[980] = (!x[325]|x[321]);// and (not _id_259 or _id_255) 
	count_nodes_vector.push_back(x[980]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(980);
	
	std::cerr<<"procesing gate 973..."<<std::endl;
	x[973] = (!x[321]|x[320])&(!x[320]|x[321]);// and (not _id_255 or _id_254) and (not _id_254 or _id_255) 
	count_nodes_vector.push_back(x[973]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(973);
	std::cerr<<"procesing gate 972..."<<std::endl;
	x[972] = x[974]&x[976]&x[978]&x[980]&x[973];//
	count_nodes_vector.push_back(x[972]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(972);
		
	std::cerr<<"procesing gate 984..."<<std::endl;
	x[984] = (!x[327]|x[326])&(!x[326]|x[327]);// and (not _id_261 or _id_260) and (not _id_260 or _id_261) 
	count_nodes_vector.push_back(x[984]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(984);
	
	std::cerr<<"procesing gate 986..."<<std::endl;
	x[986] = (!x[328]|x[326])&(!x[326]|x[328]);// and (not _id_262 or _id_260) and (not _id_260 or _id_262) 
	count_nodes_vector.push_back(x[986]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(986);
	
	std::cerr<<"procesing gate 988..."<<std::endl;
	x[988] = (!x[329]|x[326])&(!x[326]|x[329]);// and (not _id_263 or _id_260) and (not _id_260 or _id_263) 
	count_nodes_vector.push_back(x[988]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(988);
	
	std::cerr<<"procesing gate 983..."<<std::endl;
	x[983] = (!x[326]|x[320])&(!x[320]|x[326]);// and (not _id_260 or _id_254) and (not _id_254 or _id_260) 
	count_nodes_vector.push_back(x[983]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(983);
	std::cerr<<"procesing gate 982..."<<std::endl;
	x[982] = x[984]&x[986]&x[988]&x[983];//
	count_nodes_vector.push_back(x[982]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(982);
	
	std::cerr<<"procesing gate 971..."<<std::endl;
	x[971] = (!x[320]|x[210])&(!x[210]|x[320]);// and (not _id_254 or business_management) and (not business_management or _id_254) 
	count_nodes_vector.push_back(x[971]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(971);
	std::cerr<<"procesing gate 970..."<<std::endl;
	x[970] = x[972]&x[982]&x[971];//
	count_nodes_vector.push_back(x[970]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(970);
	
	std::cerr<<"procesing gate 751..."<<std::endl;
	x[751] = (!x[210]|x[0])&(!x[0]|x[210]);// and (not business_management or eShop) and (not eShop or business_management) 
	count_nodes_vector.push_back(x[751]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(751);
	std::cerr<<"procesing gate 750..."<<std::endl;
	x[750] = x[752]&x[810]&x[930]&x[936]&x[940]&x[950]&x[958]&x[970]&x[751];//
	count_nodes_vector.push_back(x[750]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(750);
	
	std::cerr<<"procesing gate 331..."<<std::endl;
	x[331] = (x[0]);//(eShop) 
	count_nodes_vector.push_back(x[331]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(331);
	std::cerr<<"procesing gate 330..."<<std::endl;
	x[330] = x[332]&x[750]&x[331];//
	count_nodes_vector.push_back(x[330]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(330);
		
	std::cerr<<"procesing gate 992..."<<std::endl;
	x[991] = !x[103]|x[104];//not wish_list or wish_list_saved_after_session
	count_nodes_vector.push_back(x[991]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(992);
	
	std::cerr<<"procesing gate 993..."<<std::endl;
	x[992] = x[14]|x[104];//registration or wish_list_saved_after_session
	count_nodes_vector.push_back(x[992]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(993);
	
	std::cerr<<"procesing gate 994..."<<std::endl;
	x[993] = !x[51]|x[75];//not eletronic_goods or size
	count_nodes_vector.push_back(x[993]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(994);
	
	std::cerr<<"procesing gate 995..."<<std::endl;
	x[994] = !x[52]|x[75];//not physical_goods or size
	count_nodes_vector.push_back(x[994]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(995);
	
	std::cerr<<"procesing gate 996..."<<std::endl;
	x[995] = !x[51]|x[234];//not eletronic_goods or eletronic_goods_fulfillment
	count_nodes_vector.push_back(x[995]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(996);
	
	std::cerr<<"procesing gate 997..."<<std::endl;
	x[996] = !x[46]|x[204];//not user_behaviour_tracking_info or user_behaviour_tracking
	count_nodes_vector.push_back(x[996]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(997);
	
	std::cerr<<"procesing gate 998..."<<std::endl;
	x[997] = !x[122]|x[44];//not quick_checkout or quick_checkout_profile
	count_nodes_vector.push_back(x[997]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(998);
	
	std::cerr<<"procesing gate 999..."<<std::endl;
	x[998] = !x[243]|x[38];//not customer_preferences or preferences
	count_nodes_vector.push_back(x[998]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(999);
	
	std::cerr<<"procesing gate 1000..."<<std::endl;
	x[999] = !x[53]|x[237];//not services or services_fulfillment
	count_nodes_vector.push_back(x[999]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1000);
	
	std::cerr<<"procesing gate 1001..."<<std::endl;
	x[1000] = !x[52]|x[214];//not physical_goods or physical_goods_fulfillment
	count_nodes_vector.push_back(x[1000]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1001);
	
	std::cerr<<"procesing gate 1002..."<<std::endl;
	x[1001] = !x[248]|x[103];//not wish_list_content or wish_list
	count_nodes_vector.push_back(x[1001]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1002);
	
	std::cerr<<"procesing gate 1003..."<<std::endl;
	x[1002] = !x[121]|x[18];//not registered_checkout or register_to_buy
	count_nodes_vector.push_back(x[1002]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1003);
	
	std::cerr<<"procesing gate 1004..."<<std::endl;
	x[1003] = !x[121]|x[15];//not registered_checkout or registration_enforcement
	count_nodes_vector.push_back(x[1003]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1004);
	
	std::cerr<<"procesing gate 1005..."<<std::endl;
	x[1004] = !x[125]|x[216];//not shipping_options or shipping
	count_nodes_vector.push_back(x[1004]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1005);
	
	std::cerr<<"procesing gate 1006..."<<std::endl;
	x[1005] = !x[249]|x[207]|x[208];//not previously_visited_pages or locally_visited_pages or external_referring_pages
	count_nodes_vector.push_back(x[1005]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1006);
	
	std::cerr<<"procesing gate 1007..."<<std::endl;
	x[1006] = !x[9]|x[266];//not special_offers or discounts
	count_nodes_vector.push_back(x[1006]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1007);
	
	std::cerr<<"procesing gate 1008..."<<std::endl;
	x[1007] = !x[77]|x[303];//not availability or inventory_tracking
	count_nodes_vector.push_back(x[1007]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1008);
	
	std::cerr<<"procesing gate 1009..."<<std::endl;
	x[1008] = !x[52]|x[76];//not physical_goods or weight
	count_nodes_vector.push_back(x[1008]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1009);
	
	std::cerr<<"procesing gate 1010..."<<std::endl;
	x[1009] = !x[91]|x[79];//not category_page or categories
	count_nodes_vector.push_back(x[1009]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1010);
	
	std::cerr<<"procesing gate 1011..."<<std::endl;
	x[1010] = !x[107]|x[14];//not permissions or registration
	count_nodes_vector.push_back(x[1010]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1011);
	
	std::cerr<<"procesing gate 1012..."<<std::endl;
	x[1011] = !x[105]|x[14];//not email_wish_list or registration
	count_nodes_vector.push_back(x[1011]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(1012);
	std::cerr<<"procesing gate 991..."<<std::endl;
	x[1012] = x[991]&x[992]&x[993]&x[994]&x[995]&x[996]&x[997]&x[998]&x[999]&x[1000]&x[1001]&x[1002]&x[1003]&x[1004]&x[1005]&x[1006]&x[1007]&x[1008]&x[1009]&x[1010]&x[1011];//
	count_nodes_vector.push_back(x[1012]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(991);
	std::cerr<<"procesing gate 990..."<<std::endl;
	x[990] = x[1012]&x[330];//
	count_nodes_vector.push_back(x[990]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(990);
  t2 = get_user_time();
  
  t4 = get_diftime(t1,t2);

  	output[0]=x[330];

	output[1]=x[1012];

  

  //symmetry  sorting
  std::cerr<<"Setting order symmetry ..."<<std::endl;
  
  
  t1 = get_user_time();
  std::cerr<<"Reducing heap order symmetry reorder CUDD_REORDER_SIFT ..."<<std::endl;
  mgr.ReduceHeap(CUDD_REORDER_SIFT);
  t2 = get_user_time();
  t3 = get_diftime(t1,t2);
  
  minTerms =  x[990].CountMinterm(290);
          
  sprintf(buffer,"%g\t%g\t%g",t4,t3,minTerms);
          
  

  
  std::string symmetric = totalSymmetric(mgr,290);
  std::cerr<<"Calculated groups:"<<68<<std::endl;
  
  
  
  std::cerr<<"\t"<<"Group1:[5, 6]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group2:[8, 9]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group3:[12, 13]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group4:[14, 15]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group5:[17, 18, 19]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group6:[20, 21]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group7:[26, 27]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group8:[33, 34, 35, 36]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group9:[40, 41, 42]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group10:[1, 47]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group11:[48, 49]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group12:[51, 52, 53]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group13:[60, 61]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group14:[63, 71, 72]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group15:[65, 66, 67, 68, 69, 70]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group16:[79, 80]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group17:[87, 88]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group18:[89, 90]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group19:[95, 96, 97, 98, 99]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group20:[109, 110, 111]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group21:[113, 114]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group22:[121, 124]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group23:[125, 130]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group24:[118, 131]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group25:[137, 138]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group26:[139, 140]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group27:[144, 145, 146]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group28:[133, 147]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group29:[149, 150]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group30:[153, 154, 155]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group31:[156, 157]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group32:[159, 160, 161, 162, 163, 164, 165, 166, 167]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group33:[171, 172, 173, 174, 175, 176, 177]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group34:[112, 178]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group35:[180, 181, 182, 183]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group36:[185, 186]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group37:[190, 192, 193, 200]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group38:[196, 197, 198]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group39:[202, 203]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group40:[204, 205]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group41:[207, 208, 209]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group42:[0, 210]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group43:[211, 212]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group44:[214, 215]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group45:[218, 227]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group46:[219, 220]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group47:[223, 224, 225, 226]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group48:[229, 230, 231, 232, 233]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group49:[234, 235]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group50:[240, 241]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group51:[243, 244, 245, 246, 247, 248, 249, 250, 251]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group52:[254, 255]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group53:[257, 258]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group54:[262, 263]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group55:[267, 268]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group56:[273, 274, 275]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group57:[266, 279]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group58:[281, 282]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group59:[288, 289]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group60:[290, 291]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group61:[294, 295, 296]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group62:[300, 302]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group63:[306, 307]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group64:[308, 309]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group65:[310, 312]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group66:[316, 317, 318, 319]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group67:[321, 324]"<<std::endl;
  
  
  std::cerr<<"\t"<<"Group68:[320, 326]"<<std::endl;
  
  

  str_output = "symmetry	CUDD_REORDER_SIFT	0.6400000000";
  str_output = str_output + "\t" + buffer + "\t5349\t290.0	351.0	2.0	0.7800373317614634	0.3265532273965427	0.6896551724137931	55.86206896551724	62.42046068405384	55.86206896551724	0.7800373317614705	0.5737505315647994	0.5698005698005698	9.193103448275862	2.1782077383021017	9.0";
  
  str_output = str_output + "\t" + symmetric;
  
  print_output(1013,"Electronic Shopping",str_output, mgr,output,true,&(x[990]),true);
  writeSize("growth.txt","Electronic Shopping","symmetry",count_nodes,count_id);
  

  
  std::cerr<<"minterms (CUDD):"<<x[990].CountMinterm(290)<<std::endl;
  

  

}

