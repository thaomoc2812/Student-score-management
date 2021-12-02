#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct DiemSV{
	char TenSV[20];
	float DiemQT,DiemCK,DiemTK;
	char DiemXL;
};

void nhapDiem(DiemSV *ds,int *n){
	printf("Nhap so luong sinh vien : ");
	scanf("%d",n);
	while(*n<=0|| *n>40){
		printf("So sinh vien phai nam trong khoang [1;40]. Nhap lai!!!!\n");
		scanf("%d",n);
	}
	printf("Nhap thong tin tung sinh vien ! \n");
	for(int i=0; i<*n;i++){
		printf("Sinh vien thu %d :\n",i+1);
		
		printf("Ho va ten : ");
		fflush(stdin);gets(ds[i].TenSV);
		
		printf("Diem QT :");
		scanf("%f",&ds[i].DiemQT);
		while(ds[i].DiemQT <0 || ds[i].DiemQT >10){
			printf("Nhap lai diem trong khoang [0;10] : ");
			scanf("%f",&ds[i].DiemQT);
		}
		
		
		printf("Diem CK : ");
		scanf("%f",&ds[i].DiemCK);
		while(ds[i].DiemCK <0 || ds[i].DiemCK >10){
			printf("Nhap lai diem trong khoang [0;10] : ");
			scanf("%f",&ds[i].DiemCK);
		}
		ds[i].DiemTK=ds[i].DiemQT*0.4 + ds[i].DiemCK*0.6;
		if(ds[i].DiemQT <=3 || ds[i].DiemCK <=3 ) ds[i].DiemXL = 'F';
		else if(ds[i].DiemTK < 4 ) ds[i].DiemXL = 'F';
		    else if(ds[i].DiemTK >= 4 && ds[i].DiemTK <5.5) ds[i].DiemXL = 'D';
		         else if(ds[i].DiemTK >= 5.5 && ds[i].DiemTK <7) ds[i].DiemXL = 'C';
		              else if(ds[i].DiemTK >=7 && ds[i].DiemTK <8.5)ds[i].DiemXL = 'B';
		                    else ds[i].DiemXL = 'A';
		
	}
}



 void inBangDiem(DiemSV *ds,int n){
	printf("   Ten SV   |   Diem QT  |    Diem CK    |    Diem XL   \n");
	for(int i=0;i<n;i++){
	printf("%s     |     %.1f     |       %.1f       |      %c      \n",ds[i].TenSV,ds[i].DiemQT,ds[i].DiemCK,ds[i].DiemXL);
};
}

void chenhLechDiem(DiemSV *ds,int n){
	int l;
	printf("Nhap vao so nguyen L ban muon trong khoang [2;5]: ");
	scanf("%d",&l);
	while(l>5||l<2){
		printf("Nhap lai !");
		scanf("%d",&l);
	}
	printf("Sinh vien co diem chenh lech thoa man dieu kien : \n");
	printf("   Ten SV   |   Diem QT  |    Diem CK    |    Diem XL   \n");
	for(int i =0;i<n;i++){
		if(ds[i].DiemQT - ds[i].DiemCK >=l || ds[i].DiemCK - ds[i].DiemQT >=l )
		printf("%s     |     %.1f     |       %.1f       |      %c      \n",ds[i].TenSV,ds[i].DiemQT,ds[i].DiemCK,ds[i].DiemXL);
		
	};
}

void sapxep(DiemSV *ds,int n){
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			if(ds[j].DiemTK>ds[j-1].DiemTK){
				char tmp_ten[20];float tmp_diemQT,tmp_diemCK,tmp_diemTK; char tmp_XL;
				
				strcpy(tmp_ten,ds[j-1].TenSV);
				tmp_XL = ds[j-1].DiemXL;
				tmp_diemQT=ds[j-1].DiemQT;
				tmp_diemCK=ds[j-1].DiemCK;
				tmp_diemTK=ds[j-1].DiemTK;
				
				
				strcpy(ds[j-1].TenSV,ds[j].TenSV);
				ds[j-1].DiemXL = ds[j].DiemXL;
				ds[j-1].DiemQT = ds[j].DiemQT;
				ds[j-1].DiemCK = ds[j].DiemCK;
				ds[j-1].DiemTK = ds[j].DiemTK;
				
				strcpy(ds[j].TenSV,tmp_ten);
				ds[j].DiemXL = tmp_XL;
				ds[j].DiemQT = tmp_diemQT;
				ds[j].DiemCK = tmp_diemCK;
				ds[j].DiemTK = tmp_diemTK;
				
			}
		}
	}
	
	
	for(int i=0;i<n;i++){
		if(ds[i].DiemTK==ds[i+1].DiemTK){
			
			for(int i=n;i>1;i--){
		      for(int j=1;j<i;j++){
			    if(strcmp(ds[j].TenSV,ds[j+1].TenSV)>0){
				char tmp_ten[20];float tmp_diemQT,tmp_diemCK,tmp_diemTK; char tmp_XL;
				
				strcpy(tmp_ten,ds[j-1].TenSV);
				tmp_XL = ds[j-1].DiemXL;
				tmp_diemQT=ds[j-1].DiemQT;
				tmp_diemCK=ds[j-1].DiemCK;
				tmp_diemTK=ds[j-1].DiemTK;
				
				
				strcpy(ds[j-1].TenSV,ds[j].TenSV);
				ds[j-1].DiemXL = ds[j].DiemXL;
				ds[j-1].DiemQT = ds[j].DiemQT;
				ds[j-1].DiemCK = ds[j].DiemCK;
				ds[j-1].DiemTK = ds[j].DiemTK;
				
				strcpy(ds[j].TenSV,tmp_ten);
				ds[j].DiemXL = tmp_XL;
				ds[j].DiemQT = tmp_diemQT;
				ds[j].DiemCK = tmp_diemCK;
				ds[j].DiemTK = tmp_diemTK;
				
			}
		}
	}
		}
	}
}


int main(){
	
	DiemSV ds[40];
	int n;
	int key;
	do{
		
		
	printf("^^^^^^^^CHUONG TRINH QUAN LY DIEM MON HOC^^^^^^^^^^^^\n");
	printf("^               1.Nhap Diem                         ^\n");
	printf("^               2.In bang diem                      ^\n");
	printf("^               3.Chenh lech diem                   ^\n");
	printf("^               4.Sap xep                           ^\n");
	printf("^               5.Thoat chuong trinh                ^\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("Nhap thao tac : ");
	scanf("%d",&key);
	switch (key){
		case 1:
			nhapDiem(ds,&n);
			break;
		case 2:
			inBangDiem(ds,n);
			break;
		case 3:
			chenhLechDiem(ds,n);
			break;
		case 4:
			sapxep(ds,n);
			break;
			
	};
	}while(key!=5);
	printf("********************THANK YOU*************************");
	return 0;
	}
