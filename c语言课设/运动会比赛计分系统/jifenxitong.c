#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long N,M,W;
FILE *fp;
typedef struct ee{
	char XueXiaoMingChen[100];
	struct ee *next;
}XueXiao;
typedef struct cc{
	char XiangMuMC[100];
	struct cc *next;
}XM;
typedef struct vv{
	char XiangMuMC[100];
	struct vv *next;
}XMN;
typedef struct ft{
	char XMMC[100];
	char HuoJiangYunDongYuan[100];
	char SuoShuXueXiao[100];
	int mingci;
	int fenshu;
	struct ft *next;
}GXMHuoJiangXXi;
long long getint(){
	long long tem;
	long long i,l,m;
	char s[100];
	while(1){
		m=0;
		gets(s);
		l=strlen(s);
		for(i=0;i<l;i++){
			if(s[i]>='0'&&s[i]<='9')
			  ++m;
		}
		if(((tem=atoi(s))||tem == 0)&&m==l)
		return tem;
		printf("输入错误！请再次输入：\n");
	}
} 
long long CaiDan();
XueXiao *X=NULL;
XM *Y = NULL;
XMN *Z = NULL;
GXMHuoJiangXXi  *head = NULL;
long long sum = 0;
 
void ChuShiHua(){
	printf("请输入学校总数： ");
	N = getint();
	printf(" 请输入这些学校的名字： \n");
	long long i; 
	XueXiao *pt1,*prept1;
	if(fp = fopen("运动会计分.txt","w+") == NULL){
	    printf("打开文件失败！");
	    exit(0) ;
	}
	for(i=1;i<=N;i++){
		printf("  第%d个：",i);
		pt1 = (XueXiao *)malloc(sizeof(XueXiao));
		scanf("%s",pt1->XueXiaoMingChen);
		fprintf(fp,"%s  ",pt1->XueXiaoMingChen);
		if(i == 1){
			X = prept1 = pt1;
		    pt1->next = NULL;
		}
		else{
			prept1->next = pt1;
			pt1->next = NULL;
			prept1 = pt1 ;
		}
	}
	fprintf(fp,"\n");
	getchar();
	printf("请输入男子项目总数： ");
	M = getint(); 
	printf(" 请输入这些项目的名字： \n");
	XM *pt2,*prept2; 
	for(i=1;i<=M;i++){
		printf("  第%d个：",i);
		pt2 = (XM *)malloc(sizeof(XM));
		scanf("%s",pt2->XiangMuMC );
		fprintf(fp,"%s  ",pt2->XiangMuMC);
		if(i == 1){
			Y = prept2 = pt2;
		    pt2->next = NULL;
		}
		else{
			prept2->next = pt2;
			pt2->next = NULL;
			prept2 = pt2 ;
		}
	}
	fprintf(fp,"\n");
	getchar();
	printf("请输入女子项目总数： ");
	W = getint();
	printf(" 请输入这些项目的名字： \n");
	XMN *pt3,*prept3; 
	for(i=1;i<=W;i++){
		printf("  第%d个：",i);
		pt3 = (XMN *)malloc(sizeof(XMN));
		scanf("%s",pt3->XiangMuMC  );
		fprintf(fp,"%s ",pt3->XiangMuMC);
		if(i == 1){
			Z = prept3 = pt3;
		    pt3->next = NULL;
		    
		}
		else{
			prept3->next = pt3;
			pt3->next = NULL;
			prept3 = pt3 ;
		}
	}
	fprintf(fp,"\n");
	fclose(fp);
	getchar();
    printf("按回车键继续操作........");
	getchar();	
	system("cls");
	CaiDan(); 
}
void BiSaiJieGuo(){
	XM *ptH = Y;
	GXMHuoJiangXXi *pt=NULL,*prept=NULL;
	int n1,i,e=0;
	fp = fopen("运动会计分.txt","r+");
	fseek(fp,0L,SEEK_END);
	while(ptH!=NULL){
		printf("请输入%s的比赛结果：\n",ptH->XiangMuMC);
		printf("输入该项目取前5/3名： ");
		n1 = getint();
		while(n1!=5&&n1!=3){
		         printf("输入错误!请重新输入:\n");
		         n1 = getint();
	    }
		for(i=1;i<=n1;i++){
			++e;
		    pt = (GXMHuoJiangXXi *)malloc(sizeof(GXMHuoJiangXXi));
		    strcpy(pt->XMMC,ptH->XiangMuMC);
	        printf("请输入获奖运动员名字： ");
	        scanf("%s",pt->HuoJiangYunDongYuan );
	        printf("请输入运动员所在学校： ");
	        scanf("%s",pt->SuoShuXueXiao );
	        getchar(); 
			printf("请输入运动员名次： ");
			pt->mingci = getint();
			while(pt->mingci > n1||pt->mingci <= 0){
		            printf("输入错误!请重新输入:\n");
		            pt->mingci = getint();
	        } 
			fprintf(fp,"%s   ",pt->XMMC);
			fprintf(fp,"%s   ",pt->HuoJiangYunDongYuan );
		    fprintf(fp,"%s   ",pt->SuoShuXueXiao );
			fprintf(fp,"第%d名\n",pt->mingci );
			if(n1 == 3){
				if(pt->mingci == 1)
				pt->fenshu = 5;
				else if(pt->mingci == 2)
				pt->fenshu = 3;
				else
				pt->fenshu = 2;
			}
			else {
				if(pt->mingci == 1)
				pt->fenshu = 7;
				else if(pt->mingci == 2)
				pt->fenshu = 5;
				else if(pt->mingci == 3)
				pt->fenshu = 3;
				else if(pt->mingci == 4)
				pt->fenshu = 2;
				else
				pt->fenshu = 1;
			}
			if(e==1){
	        	head = prept = pt ;
	            pt->next = NULL;
			}
			else{
				prept->next = pt;
				pt->next = NULL;
				prept = pt;
			}
	    }
	    ptH = ptH->next ;
	}
	XMN *pth = Z;
	while(pth!=NULL){
		printf("\n请输入%s的比赛结果：\n",pth->XiangMuMC);
		printf("输入该项目取前5/3名： ");
		n1 = getint();
		while(n1!=5&&n1!=3){
		         printf("输入错误!请重新输入:\n");
		         n1 = getint();
	    }
		for(i=1;i<=n1;i++){
			++e;
		    pt = (GXMHuoJiangXXi *)malloc(sizeof(GXMHuoJiangXXi));
		    strcpy(pt->XMMC,pth->XiangMuMC);
	        printf("请输入获奖运动员名字： ");
	        scanf("%s",pt->HuoJiangYunDongYuan );
	        printf("请输入运动员所在学校： ");
	        scanf("%s",pt->SuoShuXueXiao );
	        getchar();
			printf("请输入运动员名次： ");
			pt->mingci = getint();
			while(pt->mingci > n1||pt->mingci <=0){
		            printf("输入错误!请重新输入:\n");
		            pt->mingci = getint();
	        } 
			fprintf(fp,"%s   ",pt->XMMC);
			fprintf(fp,"%s   ",pt->HuoJiangYunDongYuan );
		    fprintf(fp,"%s   ",pt->SuoShuXueXiao );
			fprintf(fp,"第%d名\n",pt->mingci );
			if(n1 == 3){
				if(pt->mingci == 1)
				pt->fenshu = 5;
				else if(pt->mingci == 2)
				pt->fenshu = 3;
				else
				pt->fenshu = 2;
			}
			else {
				if(pt->mingci == 1)
				pt->fenshu = 7;
				else if(pt->mingci == 2)
				pt->fenshu = 5;
				else if(pt->mingci == 3)
				pt->fenshu = 3;
				else if(pt->mingci == 4)
				pt->fenshu = 2;
				else
				pt->fenshu = 1;
			}
			if(e==1){
	        	head = prept = pt ;
	            pt->next = NULL;
			}
			else{
				prept->next = pt;
				pt->next = NULL;
				prept = pt;
			}
	    }
	    pth = pth->next ;
	}
	fclose(fp);
	getchar();
    printf("按回车键继续操作........");
	getchar();	
	system("cls");
	CaiDan();
}
void XueXiaoBiSaiCJi(){
	char s1[100];
	sum = 0;
	GXMHuoJiangXXi *pt = head;
	scanf("%s",s1);
	while(pt!=NULL){
		if(!strcmp(s1,pt->SuoShuXueXiao)){
			printf("%s  %s  %s  第%d名  得%d分\n",pt->SuoShuXueXiao ,pt->HuoJiangYunDongYuan,pt->XMMC,pt->mingci,pt->fenshu);
			sum += pt->fenshu ;
		}
		pt = pt->next ;
	}getchar(); 
	printf("%s总共获得%d分\n\n",s1,sum);
    printf("按回车键继续操作........");
	getchar();
	system("cls");
	CaiDan();
}
void AllXueXiaoBiSaiCJi(){
	XueXiao *ptt = X;
	GXMHuoJiangXXi *pt = head;
	sum = 0; 
	while(ptt!=NULL){
		while(pt!=NULL){
		if(!strcmp(ptt->XueXiaoMingChen,pt->SuoShuXueXiao )){
			printf("%s  %s  %s  第%d名  得%d分\n",pt->SuoShuXueXiao ,pt->HuoJiangYunDongYuan,pt->XMMC,pt->mingci,pt->fenshu);
			sum += pt->fenshu ;
		}
		pt = pt->next ;
        }    
	    printf("%s总共获得%d分\n\n",ptt->XueXiaoMingChen,sum);
	    sum = 0;
        ptt = ptt->next;
        pt = head;
	}
    printf("按回车键继续操作........");
	getchar();
	system("cls");
	CaiDan();
}
void ChaKanXueXiao(){
	  XueXiao *pt = X;
	   while(pt != NULL){
	   	printf("%s\n",pt->XueXiaoMingChen);
	   	pt = pt->next ;
	   }
    printf("按回车键继续操作........");	
    getchar();
	system("cls");
	CaiDan();
}
void ChaKanXiangMu(){
	XM *pt = Y;
	while(pt != NULL){
		printf("%s\n",pt->XiangMuMC);
		pt = pt->next ;
	}
}
void ChaKanXiangMuN(){
	XMN *pt = Z;
	while(pt != NULL){
		printf("%s\n",pt->XiangMuMC );
		pt = pt->next ;
	}
    printf("按回车键继续操作........");	
    getchar();
	system("cls");
	CaiDan();
}
long long CaiDan(){
	printf("请选择输入序号：\n");
	printf("1. 初始化输入(首先必须初始化)\n2. 输入比赛结果\n3. 查询学校的比赛成绩\n4. 查看参赛学校信息\n5. 查看比赛项目信息\n6. 结束\n");
	long long n = getint();
	if(n == 6) exit(0);
	while((n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5)&&(n!=6)){
		printf("输入错误！请重新输入:\n");
		n = getint();
	}
	
	switch(n){
		case 1:
        	ChuShiHua();
        	break;
		case 2:
			BiSaiJieGuo();
			break;
		case 3:
			printf("1. 查看所有学校比赛成绩\n2. 查看指定学校比赛成绩\n");
			printf("请选择输入序号：");
			long long n2;
			n2 = getint();
			while(n2!=1&&n2!=2){
		        printf("输入错误!请重新输入:\n");
		        n = getint();
	        }
			if(n2 == 1)
			  AllXueXiaoBiSaiCJi();
			else{
	          printf("请输入学校的名字：\n");
			  XueXiaoBiSaiCJi();
		    }
	    case 4:
	    	ChaKanXueXiao();break; 
	    case 5:
	    	ChaKanXiangMu();
			ChaKanXiangMuN();
	    	break;
	} 
}
int main()
{
	CaiDan();
    return 0;
} 
