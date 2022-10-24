#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

void vytvorPar(FILE * f, int poziceX, int poziceY){
	fprintf(f, "<circle r=\"13\"   cy=\"%d\"  cx=\"%d\"  id=\"path847\" style=\"opacity:1;fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:1.5;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1\"/>\n", poziceY, poziceX);
	fprintf(f, "<circle r=\"13\"   cy=\"%d\"  cx=\"%d\"  id=\"path847\" style=\"opacity:1;fill:#008000;fill-opacity:1;stroke:#000000;stroke-width:1.5;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1\"/>\n", poziceY, poziceX + 26);
}

void vytvorPozadi(FILE * f, int poziceX, int poziceY, int width, int height, int id){
	fprintf(f, "<rect style=\"opacity:1;fill:#ffffff;fill-opacity:1;stroke:#000000;stroke-width:0;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1\" id=\"%d\" width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" />", id, width, height, poziceX, poziceY);

}


void vytvorKruh(FILE * f, int poziceX, int poziceY, int velikost){
	fprintf(f, "<circle r=\"%d\"   cy=\"%d\"  cx=\"%d\"  id=\"path847\" style=\"opacity:1;fill:#ffff00;fill-opacity:1;stroke:#000000;stroke-width:1.5;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1\"/>\n",velikost, poziceY, poziceX);
}


void vytvorKinesin(FILE * f, int poziceX, int poziceY, float scale){
	int i = 5;
	fprintf(f, "<g transform=\"translate(%d,%d) scale(%f %d)\" id=\"layer1-6\" inkscape:label=\"Layer 1\"> <g id=\"g2538\" transform=\"matrix(0.26458333,0,0,0.26458333,-73.300519,311.76468)\"> <path style=\"fill:none;stroke:#ff0000;stroke-width:5;stroke-linecap:butt;stroke-linejoin:miter;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1\" d=\"m 307.04851,-317.56015 c 0,0 -10.29717,16.4879 -9.60638,26.06747 0.69076,9.57957 11.76138,15.56702 11.43354,25.27059 -0.30015,8.88414 -10.15435,13.25548 -9.99842,22.1888 0.15586,8.93333 10.78895,13.92668 10.92297,23.18813 0.134,9.26144 -10.12206,13.24106 -9.052,22.4222 1.07007,9.18113 6.96542,11.21058 8.82765,18.18249 1.86224,6.97192 -7.24933,8.81321 -4.05918,14.84542 3.19015,6.0322 16.23252,1.69773 16.88408,10.1389 0.65158,8.44117 -16.65942,8.28927 -22.85805,14.45337 -6.19861,6.16412 15.21921,7.16074 15.49121,19.37142 0.272,12.21067 -17.03038,11.48018 -15.04629,20.12825 2.55146,11.417609 23.745,11.678722 25.64447,24.800015 0.78792,9.926307 -8.07568,10.126628 -18.16967,16.408196\" id=\"path6805\" inkscape:connector-curvature=\"0\" sodipodi:nodetypes=\"czszzzzzzzzccc\" /> <path style=\"fill:none;stroke:#0000ff;stroke-width:5;stroke-linecap:butt;stroke-linejoin:miter;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1\" d=\"m 301.07477,-317.90818 c 0,0 10.29717,16.4879 9.60638,26.06747 -0.69076,9.57957 -11.76138,15.56702 -11.43354,25.27059 0.30015,8.88414 10.15435,13.25548 9.99842,22.1888 -0.15586,8.93333 -10.78895,13.92668 -10.92297,23.18813 -0.134,9.26144 10.12206,13.24106 9.052,22.4222 -1.07007,9.18113 -6.96542,11.21058 -8.82765,18.18249 -1.86224,6.97192 7.24933,8.81321 4.05918,14.84542 -3.19015,6.0322 -16.23252,1.69773 -16.88408,10.1389 -0.65158,8.44117 16.65942,8.28927 22.85805,14.45337 6.19861,6.16412 -15.21921,7.16074 -15.49121,19.37143 -0.272,12.21067 17.03038,11.48018 15.04629,20.12825 -2.55146,11.417609 -23.745,11.678719 -25.64447,24.800019 -0.78792,9.9263 8.07568,10.12662 18.16967,16.40819\" id=\"path6805-6\" inkscape:connector-curvature=\"0\" sodipodi:nodetypes=\"czszzzzzzzzccc\" /> </g> </g>", poziceX, poziceY, i*scale, i);
}

void zacni(FILE * f, int w, int h){
	fprintf(f, "<?xml version=\"1.0\"?> <!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"> <svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", w, h);
}

void ukonci(FILE * f){
	fprintf(f, "</svg>");
}

void cara(FILE * f, float x1, float y1, float x2, float y2, float tloustka){
	fprintf(f, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,0,0);stroke-width:%f\" />", (double)x1, (double)y1, (double)x2, (double)y2, (double)tloustka);
}

void trojuhelnik(FILE * f, float x1, float y1, float x2, float y2, float x3, float y3){
	fprintf(f, "<polygon points=\"%f,%f %f,%f %f,%f\" style=\"fill:black;stroke:purple;stroke-width:0\" />", (double)x1, (double)y1, (double)x2, (double)y2, (double)x3, (double)y3);
}

void zapisCislo(FILE * f, float x, float y, float cislo, float velikostPisma, int nd){
	switch(nd){
		case 1:
			fprintf(f, " <text x=\"%f\" y=\"%f\" font-size=\"%f\" fill=\"black\">%.1f</text>", x, y, (double)velikostPisma, cislo);
			return;

		case 2:
			fprintf(f, " <text x=\"%f\" y=\"%f\" font-size=\"%f\" fill=\"black\">%.2f</text>", x, y, (double)velikostPisma, cislo);
			return;

		case 3:
			fprintf(f, " <text x=\"%f\" y=\"%f\" font-size=\"%f\" fill=\"black\">%.3f</text>", x, y, (double)velikostPisma, cislo);
			return;
	}
	fprintf(f, " <text x=\"%f\" y=\"%f\" font-size=\"%f\" fill=\"black\">%f</text>", x, y, (double)velikostPisma, cislo);
}



int main(void){
	FILE * f = fopen("../hustomer1.svg", "w");
	
	int i = 0;
	float ii = 0;

	int w = 280;
	int w2 = 70;
	int h = 1000;
	
	zacni(f, (w + w2), h);

	double max;
	printf("zadejte maximum Sasova linearniho hustomeru: ");
	scanf("%lf",&max);

	//printf("%f", max);
	
	printf("zadejte pocet car (doporuceno 1000): ");

	int vel;

	scanf("%d", &vel);
	
	for(i = 0; i < vel; i++){
		if((float)w/2 - (2*max*i) - max/2 > 0) trojuhelnik(f, (float)w/2, (float)h, (float)w/2 - (2*max*i) - max/2,0, (float)w/2 - (2*max*i) + max/2,0);
		else{
			double k = ((double)w/(double)2)/((double)2*(double)max*(double)i);
			trojuhelnik(f, (float)w/2, (float)h, - max * k /2,(double)h - k * (double)h, max * k / 2,(double)h - k * (double)h);
		
		}
		
		if((float)w/2 + (2*max*i) + max/2 < w && i != 0) trojuhelnik(f, (float)w/2, (float)h, (float)w/2 + (2*max*i) - max/2,0, (float)w/2 + (2*max*i) + max/2,0);
		else if(i != 0){
			double k = ((double)w/(double)2)/((double)2*(double)max*(double)i);
			trojuhelnik(f, (float)w/2, (float)h, (float)w - max * k /2,(double)h - k * (double)h, w + max * k / 2,(double)h - k * (double)h);
		}
	}

	int b = 2;
	int a = 20;
	float dd = 0.1;
	float tl = 3;
	float v = w2 - 28;
	for(i = 0; i < b; i++){
		for(ii = 1; ii >= -dd; ii-=dd){
			cara(f, w, ii*h, w + v, ii * h, tl);
			if(i < 1) zapisCislo(f, w + v, ii * h + tl * 4 / 2, 1 - ii, tl * 6, (i+1));
		}
		v/=1.2;
		tl/= 2;
		dd/=10;
	}
	//*/
	
	printf("zadejte max pro druhy hustomer: ");
	scanf("%lf",&max);
	
	double x = (double)((double)max*(double)max)/(double)((double)1000+(double)max/(double)2)/2;
	
	printf("zmensovani po %lf", x);
	//double b = (double)((double)1000+(double)max/(double)2);
	//printf("\n %lf %lf", b, max);
	double yy = 1000;
	
	
	ukonci(f);
	
	fclose(f);
	
	f = fopen("../hustomer2.svg", "w");
	zacni(f, w + w2, h);
	i = 0;
	float c = 1;
	float c2 = 1;
	double puvm = max;
	tl = 3;
	v = w2 - 28;

	double o = puvm/10;

	double px1 = 0;
	double px2 = 0;

	while(max > 0){
		cara(f, 0, yy, w/2, yy - max, max/2);
		cara(f, w, yy, w/2, yy - max, max/2);
		if(abs(px1-max) >= o){
			px1 = (double)((double)roundf((max/puvm) * (double)10) / (double)10) * puvm;
			cara(f, w, yy, w + v, yy, tl);
			zapisCislo(f, w + v, yy, (max/puvm), tl * 6, (1));
		}
		if(abs(px2-max) >= (o/10)){
			px2 = (double)((double)roundf((max/puvm) * (double)100) / (double)100) * puvm;
			cara(f, w, yy, w + (v/1.2), yy, (tl/2));
			//zapisCislo(f, w + (v/1.2), yy, (max/puvm), tl * 3, (4));
		}

		max -= x;
		yy -= max;
	}
	ukonci(f);
	fclose(f);
/*
	f = fopen("../hustomer3.svg", "w");
	zacni(f, w + w2, h);
	i = 0;5
	
	float c = 1;
	float c2 = 1;
	double puvm = max;
	tl = 3;
	v = w2 - 28;

	double o = puvm/10;

	double px1 = 0;
	double px2 = 0;

	while(max > 0){
		cara(f, 0, yy, w/2, yy - max, max/2);
		cara(f, w, yy, w/2, yy - max, max/2);
		if(abs(px1-max) >= o){
			px1 = max;
			cara(f, w, yy, w + v, yy, tl);
			zapisCislo(f, w + v, yy, (max/puvm), tl * 6, (1));
		}
		if(abs(px2-max) >= (o/10)){
			px2 = max;
			cara(f, w, yy, w + (v/1.2), yy, (tl/2));
			zapisCislo(f, w + (v/1.2), yy, (max/puvm), tl * 3, (1));
		}

		max -= x;
		yy -= max;
	}
	ukonci(f);
	fclose(f);

	
	
	fclose(f);//*/
	return 0;
}


