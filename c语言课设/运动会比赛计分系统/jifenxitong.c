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
		printf("����������ٴ����룺\n");
	}
} 
long long CaiDan();
XueXiao *X=NULL;
XM *Y = NULL;
XMN *Z = NULL;
GXMHuoJiangXXi  *head = NULL;
long long sum = 0;
 
void ChuShiHua(){
	printf("������ѧУ������ ");
	N = getint();
	printf(" ��������ЩѧУ�����֣� \n");
	long long i; 
	XueXiao *pt1,*prept1;
	if(fp = fopen("�˶���Ʒ�.txt","w+") == NULL){
	    printf("���ļ�ʧ�ܣ�");
	    exit(0) ;
	}
	for(i=1;i<=N;i++){
		printf("  ��%d����",i);
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
	printf("������������Ŀ������ ");
	M = getint(); 
	printf(" ��������Щ��Ŀ�����֣� \n");
	XM *pt2,*prept2; 
	for(i=1;i<=M;i++){
		printf("  ��%d����",i);
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
	printf("������Ů����Ŀ������ ");
	W = getint();
	printf(" ��������Щ��Ŀ�����֣� \n");
	XMN *pt3,*prept3; 
	for(i=1;i<=W;i++){
		printf("  ��%d����",i);
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
    printf("���س�����������........");
	getchar();	
	system("cls");
	CaiDan(); 
}
void BiSaiJieGuo(){
	XM *ptH = Y;
	GXMHuoJiangXXi *pt=NULL,*prept=NULL;
	int n1,i,e=0;
	fp = fopen("�˶���Ʒ�.txt","r+");
	fseek(fp,0L,SEEK_END);
	while(ptH!=NULL){
		printf("������%s�ı��������\n",ptH->XiangMuMC);
		printf("�������Ŀȡǰ5/3���� ");
		n1 = getint();
		while(n1!=5&&n1!=3){
		         printf("�������!����������:\n");
		         n1 = getint();
	    }
		for(i=1;i<=n1;i++){
			++e;
		    pt = (GXMHuoJiangXXi *)malloc(sizeof(GXMHuoJiangXXi));
		    strcpy(pt->XMMC,ptH->XiangMuMC);
	        printf("��������˶�Ա���֣� ");
	        scanf("%s",pt->HuoJiangYunDongYuan );
	        printf("�������˶�Ա����ѧУ�� ");
	        scanf("%s",pt->SuoShuXueXiao );
	        getchar(); 
			printf("�������˶�Ա���Σ� ");
			pt->mingci = getint();
			while(pt->mingci > n1||pt->mingci <= 0){
		            printf("�������!����������:\n");
		            pt->mingci = getint();
	        } 
			fprintf(fp,"%s   ",pt->XMMC);
			fprintf(fp,"%s   ",pt->HuoJiangYunDongYuan );
		    fprintf(fp,"%s   ",pt->SuoShuXueXiao );
			fprintf(fp,"��%d��\n",pt->mingci );
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
		printf("\n������%s�ı��������\n",pth->XiangMuMC);
		printf("�������Ŀȡǰ5/3���� ");
		n1 = getint();
		while(n1!=5&&n1!=3){
		         printf("�������!����������:\n");
		         n1 = getint();
	    }
		for(i=1;i<=n1;i++){
			++e;
		    pt = (GXMHuoJiangXXi *)malloc(sizeof(GXMHuoJiangXXi));
		    strcpy(pt->XMMC,pth->XiangMuMC);
	        printf("��������˶�Ա���֣� ");
	        scanf("%s",pt->HuoJiangYunDongYuan );
	        printf("�������˶�Ա����ѧУ�� ");
	        scanf("%s",pt->SuoShuXueXiao );
	        getchar();
			printf("�������˶�Ա���Σ� ");
			pt->mingci = getint();
			while(pt->mingci > n1||pt->mingci <=0){
		            printf("�������!����������:\n");
		            pt->mingci = getint();
	        } 
			fprintf(fp,"%s   ",pt->XMMC);
			fprintf(fp,"%s   ",pt->HuoJiangYunDongYuan );
		    fprintf(fp,"%s   ",pt->SuoShuXueXiao );
			fprintf(fp,"��%d��\n",pt->mingci );
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
    printf("���س�����������........");
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
			printf("%s  %s  %s  ��%d��  ��%d��\n",pt->SuoShuXueXiao ,pt->HuoJiangYunDongYuan,pt->XMMC,pt->mingci,pt->fenshu);
			sum += pt->fenshu ;
		}
		pt = pt->next ;
	}getchar(); 
	printf("%s�ܹ����%d��\n\n",s1,sum);
    printf("���س�����������........");
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
			printf("%s  %s  %s  ��%d��  ��%d��\n",pt->SuoShuXueXiao ,pt->HuoJiangYunDongYuan,pt->XMMC,pt->mingci,pt->fenshu);
			sum += pt->fenshu ;
		}
		pt = pt->next ;
        }    
	    printf("%s�ܹ����%d��\n\n",ptt->XueXiaoMingChen,sum);
	    sum = 0;
        ptt = ptt->next;
        pt = head;
	}
    printf("���س�����������........");
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
    printf("���س�����������........");	
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
    printf("���س�����������........");	
    getchar();
	system("cls");
	CaiDan();
}
long long CaiDan(){
	printf("��ѡ��������ţ�\n");
	printf("1. ��ʼ������(���ȱ����ʼ��)\n2. ����������\n3. ��ѯѧУ�ı����ɼ�\n4. �鿴����ѧУ��Ϣ\n5. �鿴������Ŀ��Ϣ\n6. ����\n");
	long long n = getint();
	if(n == 6) exit(0);
	while((n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5)&&(n!=6)){
		printf("�����������������:\n");
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
			printf("1. �鿴����ѧУ�����ɼ�\n2. �鿴ָ��ѧУ�����ɼ�\n");
			printf("��ѡ��������ţ�");
			long long n2;
			n2 = getint();
			while(n2!=1&&n2!=2){
		        printf("�������!����������:\n");
		        n = getint();
	        }
			if(n2 == 1)
			  AllXueXiaoBiSaiCJi();
			else{
	          printf("������ѧУ�����֣�\n");
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
