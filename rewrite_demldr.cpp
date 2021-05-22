#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void rewrite_demldr(string data_path)
{

    string ldrName = data_path + "/DEM/TanDEM.ldr";
	FILE *fpInfo;
	if((fpInfo=fopen(ldrName.c_str(),"r"))==NULL)
    {
        printf("TanDEM.ldr can not be read: %s\n", ldrName.c_str());
        return;
    }
    int demType, demCol, demRow;
	double demSpacing, demLat0, demLon0;
    char buf[256];
		
    fscanf(fpInfo,"%s",buf);
	fscanf(fpInfo,"%s",buf);
	demType = atoi(buf);
    fscanf(fpInfo,"%s",buf);
	fscanf(fpInfo,"%s",buf);
	demCol = atoi(buf);
    fscanf(fpInfo,"%s",buf);
	fscanf(fpInfo,"%s",buf);
	demRow = atoi(buf);
    fscanf(fpInfo,"%s",buf);
	fscanf(fpInfo,"%s",buf);
	demSpacing = atof(buf);
    fscanf(fpInfo,"%s",buf);
	fscanf(fpInfo,"%s",buf);
	demLat0 = atof(buf);
    fscanf(fpInfo,"%s",buf);
	fscanf(fpInfo,"%s",buf);
	demLon0 = atof(buf);
	
    fclose(fpInfo);

//    cout << ldrName << endl;
//    cout << "demType = " << demType << endl;
//    cout << "demCol = " << demCol << endl;
//    cout << "demRow = " << demRow << endl;
//    cout << "demSpacing = " << demSpacing << endl;
//    cout << "demLat0 = " << demLat0 << endl;
//    cout << "demLon0 = " << demLon0 << endl;

    string enName = data_path + "/DEM/TanDEM_en.ldr";
    FILE *outfp = fopen(enName.c_str(), "w");
    if(outfp==NULL)
    {
        printf("TanDEM_en.ldr can not be writed: %s\n", enName.c_str());
        return;
    }

    fprintf(outfp,"[demType]");
    fprintf(outfp,"\n\t%d\n",demType);
    fprintf(outfp,"[demCol]");
    fprintf(outfp,"\n\t%d\n",demCol);
    fprintf(outfp,"[demRow]");
    fprintf(outfp,"\n\t%d\n",demRow);
    fprintf(outfp,"[demSpacing]");
    fprintf(outfp,"\n\t%.10e\n",demSpacing);
    fprintf(outfp,"[demLat0]");
    fprintf(outfp,"\n\t%.15f\n",demLat0);
    fprintf(outfp,"[demLon0]");
    fprintf(outfp,"\n\t%.15f\n",demLon0);

	fclose(outfp);
}

int main(int argc, char *argv[])
{
    string data_path = argv[1];
    rewrite_demldr(data_path);

    return 1;
}