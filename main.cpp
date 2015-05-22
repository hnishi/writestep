#include"nlib.h"

using namespace std;

int calc();  // calc() is empty func. (written in calc.cpp)

int main(int argc, char *argv[]){
   cout<<"Version info. writestep v1.1.1 \n";
// ##################### ARGUMENT HANDLING ##########################
// argv[1]: input file
  if( argv[1]==NULL ){
    puts("No ARGUMEMTS");
    //puts("USAGE: ./a.out (input parameter file) ");
    puts("USAGE: ./a.out (trajectory) (pdb) ");
    return 1;
  }
  cout<<"Your input files: "<<argv[1]<<" and "<<argv[2]<<endl;

// INPUT_PARAMETERS
//Inp_nishi inp1( argv[1] );
  string codname = argv[1];
  string pdbname = argv[2];
  //int step = atoi( argv[3] );

// CHECK OF pdb_nishi
	//calc();  // nothing occur
	//pdb_nishi pdb1("../samp/4wfi_cano.pdb");
	//cout<<"search_n resi 3: " << pdb1.search_n(' ', 3) <<endl;
	//pdb_nishi pdb1("3vg9_all_cut.pdb");
	//pdb1.center_r();
	//cout<<"comx_r[0] "<<pdb1.comx_r[0]<<endl;

	//pdb1.write_pdb("zzz.pdb");
	//pdb1.disp_line(pdb1.total_atom);
/*	cout<<"test, rnum[5] = "<<pdb1.rnum[5]<<endl;
	cout<<"TOTAL ATOM = "<<pdb1.rnum.size()<<endl;
	cout<<"TOTAL RESIDUE = "<<pdb1.resi_mark.size()<<endl;
	cout<<"final internal num. = "<<pdb1.resi_mark[pdb1.resi_mark.size()-1]<<endl;
*/	//for(unsigned int i=0;i<pdb1.resi_mark.size();i++){
	/*for(int i=pdb1.search_n(' ', 3)-1;i<pdb1.search_n(' ', 4)+1;i++){
		//pdb1.disp_line(pdb1.resi_mark[i]);
		pdb1.disp_line(i);
	}*/
// CHECK OF tra_nishi
	cout<<"now loading cod file \n";
	//tra_nishi tra1(inp1.read("CODNAME").c_str(),inp1.read("REFPDBNAME").c_str(),inp1.read("SELECTATOM").c_str());
	tra_nishi tra1( codname.c_str(), pdbname.c_str(), "all");
	//tra_nishi tra1("../samp/md_pra.cod","../samp/pra.pdb","protein");
	//tra_nishi tra1("../samp/for_rmsd/traj/md_small.crd","../samp/for_rmsd/traj/crystal_1st.pdb", "mainchain");
	//tra_nishi tra1("../samp/for_rmsd/traj/md_small.crd","../samp/for_rmsd/traj/crystal_1st.pdb");
	//tra_nishi tra1("samp/md_npt_10.cod","samp/10_min3.pdb",10);
	//tra_nishi tra1("samp/md_npt_10.cod","samp/md0.out.pdb",1);
	cout<<"TOTAL STEP = "<<tra1.total_step<<endl;
	//for(unsigned int i=0;i<tra1.total_step;i++){
	//for(unsigned int i=tra1.total_step-1;i<tra1.total_step;i++){
		//cout<<tra1.length_x[i]<<endl;;
		//tra1.disp_line(i);
	//}
	//tra1.pdb1->write_pdb("xxx.pdb");
	//tra1.write_step("OUTPDBNAME",tra1.total_step -1);
	//tra1.write_step("md.pdb", 0);
	//tra1.disp_line(tra1.total_step-1);
	//tra1.write_cod("zzz.pdb",1);
	//tra1.write_cod("zzz_100koma.pdb",1);
	//tra1.write_step(inp1.read("OUTPDBNAME").c_str(),atoi( inp1.read("STEPNUM").c_str() ) );
	//tra1.fix_cod_npt();
	//tra1.fix_cod(77.63074,80.07944,158.1261);  // for md_pra.cod and pra.pdb
	/*int stride = atoi( inp1.read("STRIDE").c_str() );
	if(tra1.total_step/stride>500){
		puts("Number of frames of your input is more than 500.");
		puts("You can set a third argument as a stride number when the output file is too large to show movies with some viewer.");
		puts("!!! Do you change the stride? put 'y' or 'n'");
		string yn;
		cin >> yn;
		if( yn == "y" ){
			puts("How long is the stride? enter");
			cin >> stride;
			puts("OK!!!, please wait, writing trajectory in ASCII.");
		}
	}
*/
	//char s1[sizeof(argv)] = "out_";
	//strcat();
	//cout<<"now writing trajectory in ASCII \n";
	//tra1.write_cod(inp1.read("OUTCODNAME").c_str(),stride);
	//fix_cod("out_traj.pdb",stride,float fxcell,float fycell,float fzcell);
		puts("put step number for writing pdb");
		int step;
		cin >> step;
		if( step > tra1.total_step ){
			puts("ERROR: step number is bigger than TOTAL FRAME");
			return 1;
		}
	tra1.write_step( "out_step.pdb", step );
	cout<<"output out_step.pdb\n";
	cout<<"finished!!!"<<endl;
// END
	cout<<"\nit took "<<(float)clock()/CLOCKS_PER_SEC<<" sec of CPU to execute this program"<<endl;
	return 0;
}
