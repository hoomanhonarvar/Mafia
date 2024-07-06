#include <iostream>
#include <string.h>
#include <cmath>
using namespace std ;
bool barabar(char (* a),char(* b))
{
    bool shart=true;
    if (strlen(a)==strlen(b)){
        for(int i =strlen(a)-1;i>=0;i--)
            if (a[i]!=b[i])
                shart =false;
    }
    else {
        shart=false;
    }
    return shart;

}
void hazfdastoor (char (*a ),char(*b))
{
    int n,m=0;
    for(unsigned int i =0 ; i <strlen(a);i++)
        if (a[i]==' ')
            n=i;
    n++;
    for(unsigned int i =n ; i<strlen(a); i++ )
    {
        b[i-n]=a[i];
        m++;
    }
    b[m]=0;


}
void jabja (char (*a), char(*b))
{
    int n=0;
    for(unsigned int i =0 ; i<strlen(a);i++){
        b[i]=a[i];
        n++;
    }
    b[n]=0;
}
void getdastoor (char (*a),char (*b))
{
    int c =0 ;
    for (unsigned int i =0 ; i <strlen( a); i ++){
        if (a[i]==' ')
            break;
        b[i]=a[i];
        c++;
    }
    b[c]=0;
}
void hazfdastoor1 (char (*a ),char(*b))
{
    int n,m=0;
    for(unsigned int i =0 ; i <strlen(a);i++)
        if (a[i]==' '){
            n=i;
            break;
        }
    n++;
    for(unsigned int i =n ; i<strlen(a); i++ )
    {
        b[i-n]=a[i];
        m++;
    }
    b[m]=0;


}
bool bozorgtary (char (*a),char (* b)){
    bool shart=true;
    if(barabar(a,b)){
        shart =false;
        return  shart;
    }
    if(strlen(a)>strlen(b))
        return  shart;
    if(strlen(b)>strlen(a))
    {
        shart =false;
        return shart;
    }
    for(unsigned int i =0; i <strlen(a); i++)
        if(a[i]<b[i])
                shart=false;

    return shart;


}
int main(void)
{
    //(1=اتش زن) (2=قاتل) (3=شکارچی)  (4=الهه عشق) (5=فرشته نگهبان )  (6=فرقه) (7_[(n-6)]/4+6=گرگ)  ([(n-6)]/4+7_n=روستایی)
    int n, temp,tir=2,deathnumber,zende,u=0;
    bool shart=true,ghatel=true,atashzan=true,shekarchi=true,elahe=true,fereshte=true;
    for(int i =0 ; i <39; i++){
        cout<<"--";
    }
    cout<<"~ Wellcome ~";
    for(int i =0 ; i <39; i++){
        cout<<"--";
    }
    cout<<endl<<"Enter number of players  :";

    cin>>n;
    int m =floor((n-6)/4),x=n-m-6,x1=x,list[n],f=1,burn=0,deathnaghsh[10];
    char name [n][100],burnlist[20][100],k[30],dastoor[30],line[40],deathlist[7][20],lovelist[2][10],votelist[10][20],votenum[n][5];
    char kill[]="Kill",Burn[]="Burn",vote []="Vote", love []="Love",shoot[]="Shoot",eat[]="Eat",clut[]="Clut",save[]="Save",oil[]="Oil";
    cout<<endl<<"Enter name of players :\n";
    x+=3;
    cin.ignore();
    for(int i =0 ; i <n; i++)
        cin.getline(name[i],100);
    for(int i =0 ; i <n; i ++){//نقش دهی
        temp=rand()%n+1;
        for(int k =0; k<i; k++)
            if (list[k]==temp)
            {
                temp=rand()%n+1;
                k=-1;
            }
        list[i]=temp;
    }
    for(int i=0 ; i<n; i++){//اعلام نقش
        if(list[i]==1)
            cout<<name[i]<<" : atash zan   "<<list[i]<<"    " <<i<<endl;
        if(list[i]==2)
            cout<<name[i]<<" : ghatel  "<<list[i]<<"    "<<i<<endl;
        if(list[i]==3)
            cout<<name[i]<<" : shekarchi  "<<list[i]<<"    "<<i<<endl;
        if(list[i]==4)
            cout<<name[i]<<" : elahe  "<<list[i]<<"     "<<i<<endl;
        if(list[i]==5)
            cout<<name[i]<<" : fereshte  "<<list[i]<<"   "<<i<<endl;
        if(list[i]==6)
            cout<<name[i]<<" : ferghe  "<<list[i]<<"    "<<i<<endl;
        if(list[i]>6 && list[i]<=(n-x))
            cout<<name[i]<<" : gorg   "<<list[i]<<"    "<<i<<endl;
        if(list[i]>(n-x))
            cout<<name[i]<<" : roostayie   "<<list[i]<<"    "<<i<<endl;
    }
    while(shart){

        cout<<"---------------------------~ NIGHT ~-------------------------\n";
        cout<<endl<<"befor ordring attention to :\n1) Enter love order first . \n2)elahe has only one order during the game . \n3)shekarchi has two shot .\n4) Every round you should enter 7 order if you don't have order press enter .\n5) you should enter the orders with chaptal first letter . \n   have a good game !\n";
        cout<<endl<<"enter the night orders";
        deathnumber=0;
        for(int q =0 ; q <7;q ++){//shab dastoor
            cin.getline(line,40);
            hazfdastoor(line,k);
            getdastoor(line,dastoor);

            //eat
            if (barabar(dastoor,eat)){
                if(m)
                    for(int i =0 ; i<n;i++)
                        if(barabar(k,name[i])){
                            if(list[i]>(n-x1)){
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                     }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        x--;
                                                        shekarchi=false;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }
                            }
                            if(list[i]>6 && list[i]<=(n-x1)){
                                m--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x-- ;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }
                            }
                            if(list[i]==1){
                                atashzan=false;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                    x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }

                            }
                            if(list[i]==2){
                                ghatel=false;
                                zende--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==3){
                                shekarchi=false;
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==4){
                                elahe=false;
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==5){
                                fereshte=false;
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==6){
                                f--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            jabja(k,deathlist[deathnumber]);
                            deathnumber++;
                        }
            }

            //kill
            if(barabar(dastoor,kill)){
                if(ghatel)
                    for(int i =0 ; i<n;i++)
                        if(barabar(k,name[i])){
                            if(list[i]>(n-x1)){
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==1){
                                atashzan=false;
                                zende--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]>6 && list[i]<=(n-x1)){
                                m--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==3){
                                shekarchi=false;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==4){
                                elahe=false;
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==5){
                                fereshte=false;
                                x--;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==6){
                                f--;

                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            if(list[i]==2){
                                ghatel=false;
                                deathnaghsh[deathnumber]=list[i];
                                list[i]=0;
                                for(int c=0;c<2;c++)//love shart
                                    if(barabar(k,lovelist[c])){
                                        if(c){
                                            jabja(lovelist[0],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                        else{
                                            jabja(lovelist[1],k);
                                            for(int y=0;y<n;y++)
                                                if(barabar(k,name[y])){
                                                    if(list[y]==1)
                                                        atashzan=false;
                                                    if(list[y]==2)
                                                        ghatel=false;
                                                    if(list[y]==3){
                                                        shekarchi=false;
                                                        x--;
                                                    }
                                                    if(list[y]==4){
                                                        elahe=false;
                                                        x--;
                                                    }
                                                    if(list[y]==5){
                                                        fereshte=false;
                                                        x--;
                                                    }
                                                    if(list[y]==6)
                                                        f--;
                                                    if(list[y]>(n-x1))
                                                        x--;
                                                    if(list[y]>6 && list[i]<=(n-x1))
                                                        m--;
                                                    list[y]=0;
                                                }

                                        }
                                    }


                            }
                            jabja(k,deathlist[deathnumber]);
                            deathnumber++;
                        }
            }

            //burn
            if(barabar(dastoor,Burn)){
                if(atashzan){
                    for( int j=0 ; j <=burn;j++){
                        jabja(burnlist[j],k);
                        for(int i=0;i<n;i++)
                            if(barabar(k,name[i])){
                                if(list[i]>(n-x1)){
                                    x--;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }
                                }

                                if(list[i]==1){
                                    atashzan=false;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    zende--;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                if(list[i]>6 && list[i]<=(n-x1)){
                                    m--;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                if(list[i]==3){
                                    shekarchi=false;
                                    x--;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                if(list[i]==4){
                                    elahe=false;
                                    x--;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                if(list[i]==5){
                                    fereshte=false;
                                    x--;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                if(list[i]==6){
                                    f--;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                if(list[i]==2){
                                    ghatel=false;
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }


                                }
                                jabja(k,deathlist[deathnumber]);
                                deathnumber++;

                            }


                    }
                    burn=0;
                }
            }

            //love
            if(barabar(dastoor,love)){
                if(elahe){
                    hazfdastoor1(line,k);
                    hazfdastoor(k,dastoor);
                    getdastoor(k,line);
                    jabja(line,lovelist[0]);
                    jabja(dastoor,lovelist[1]);
                    elahe=false;

                }


            }

            //oil
            if(barabar(dastoor,oil)){
                if (atashzan){
                    for(int i =0; i <n;i++)
                        if(barabar(k,name[i])){
                            jabja(k,burnlist[burn]);
                            burn++;
                        }
                }

            }

            //shoot
            if (barabar(dastoor,shoot)){
                if(shekarchi)
                    if (tir)
                        for(int i =0 ; i <n;i++)
                            if (barabar(k,name[i])){
                                if(list[i]==6){
                                    deathnaghsh[deathnumber]=list[i];
                                    list[i]=0;
                                    tir--;
                                    f--;
                                    for(int c=0;c<2;c++)//love shart
                                        if(barabar(k,lovelist[c])){
                                            if(c){
                                                jabja(lovelist[0],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                            else{
                                                jabja(lovelist[1],k);
                                                for(int y=0;y<n;y++)
                                                    if(barabar(k,name[y])){
                                                        if(list[y]==1)
                                                            atashzan=false;
                                                        if(list[y]==2)
                                                            ghatel=false;
                                                        if(list[y]==3){
                                                            shekarchi=false;
                                                            x--;
                                                        }
                                                        if(list[y]==4){
                                                            elahe=false;
                                                            x--;
                                                        }
                                                        if(list[y]==5){
                                                            fereshte=false;
                                                            x--;
                                                        }
                                                        if(list[y]==6)
                                                            f--;
                                                        if(list[y]>(n-x1))
                                                            x--;
                                                        if(list[y]>6 && list[i]<=(n-x1))
                                                            m--;
                                                        list[y]=0;
                                                    }

                                            }
                                        }





                                    jabja(k,deathlist[deathnumber]);
                                    deathnumber++;

                                }
                                else{
                                    shekarchi=false;
                                    for(int i=0 ; i<n; i ++){
                                        if(list[i]==3){
                                            deathnaghsh[deathnumber]=list[i];
                                            list[i]=0;
                                            zende--;
                                            for(int c=0;c<2;c++)//love shart
                                                if(barabar(k,lovelist[c])){
                                                    if(c){
                                                        jabja(lovelist[0],k);
                                                        for(int y=0;y<n;y++)
                                                            if(barabar(k,name[y])){
                                                                if(list[y]==1)
                                                                    atashzan=false;
                                                                if(list[y]==2)
                                                                    ghatel=false;
                                                                if(list[y]==3){
                                                                    shekarchi=false;
                                                                    x--;
                                                                }
                                                                if(list[y]==4){
                                                                    elahe=false;
                                                                    x--;
                                                                }
                                                                if(list[y]==5){
                                                                    fereshte=false;
                                                                    x--;
                                                                }
                                                                if(list[y]==6)
                                                                    f--;
                                                                if(list[y]>(n-x1))
                                                                    x--;
                                                                if(list[y]>6 && list[i]<=(n-x1))
                                                                    m--;
                                                                list[y]=0;
                                                            }

                                                    }
                                                    else{
                                                        jabja(lovelist[1],k);
                                                        for(int y=0;y<n;y++)
                                                            if(barabar(k,name[y])){
                                                                if(list[y]==1)
                                                                    atashzan=false;
                                                                if(list[y]==2)
                                                                    ghatel=false;
                                                                if(list[y]==3){
                                                                    shekarchi=false;
                                                                    x--;
                                                                }
                                                                if(list[y]==4){
                                                                    elahe=false;
                                                                    x--;
                                                                }
                                                                if(list[y]==5){
                                                                    fereshte=false;
                                                                    x--;
                                                                }
                                                                if(list[y]==6)
                                                                    f--;
                                                                if(list[y]>(n-x1))
                                                                    x--;
                                                                if(list[y]>6 && list[i]<=(n-x1))
                                                                    m--;
                                                                list[y]=0;
                                                            }

                                                    }
                                                }
                                            jabja(name[i],deathlist[deathnumber]);
                                            deathnumber++;
                                        }
                                    }
                                }
                            }


            }

            //clut
            if(barabar(dastoor,clut)){
                if(f)
                    for(int i =0 ; i <n;i ++)
                        if (barabar(k,name[i]))
                            if(list[i]==4 || list[i]==5 ||list[i]>(n-x1)){
                                list[i]=6;
                                f++;
                                x--;
                            }
            }

            //save
            if(barabar(dastoor,save)){
                if(fereshte){
                    for(int i =0 ; i<deathnumber; i++)
                        if(barabar(k,deathlist[i])){
                            if(deathnaghsh[i]==1){
                                atashzan=true;

                            }
                            if(deathnaghsh[i]==2){

                                ghatel=true;
                            }
                            if (deathnaghsh[i]==3){
                                x++;

                                shekarchi=true;
                            }
                            if(deathnaghsh[i]==4){
                                x++;

                                elahe=true;
                            }

                            if (deathnaghsh[i]==5){
                                x++;

                                fereshte=true;
                            }
                            if(deathnaghsh[i]==6){

                                f++;
                            }
                            if(deathnaghsh[i]>(n-x1)){
                                x++;
                            }
                            if(deathnaghsh[i]>6 && deathnaghsh[i]<=(n-x1)){

                                m++;
                            }

                            for(int j=0 ; j<n; j++)
                                if (barabar(k,name[j]))
                                    list[j]=deathnaghsh[i];
                        }
                    deathnumber=0;
                }
            }
        }
        zende=0;
        for(int i =0 ;  i<n; i++){
            if(list[i]!=0){
                cout<<name[i]<<"   :   Alive\n";
                zende++;
            }
        }
        for(int i=0;i<n;i++){
            if(list[i]!=0)
                cout<<"\n  "<<name[i]<<"  : Alive"<<endl;
            else
                cout<<"\n "<<name[i]<<"   : dead"<<endl;
        }
        if(zende==x){
            cout<<"\n vilagers  win !";
            shart =false;
            break;
        }
        if((m==(zende /2) ||m>(zende/2))&& !atashzan &&! ghatel ){

            cout<<"\n wolves win !";
            shart =false;
            break;
        }
        if(f==zende){
            cout<<"\n Clut win";
            shart = false ;
            break;
        }

        cout<<"\n\n-------------------------------------------~ DAY ~-----------------------------------\n";
        //shart ro chek kon.
        vote :

        cout<<endl;
        zende=0;
        for(int i =0 ;  i<n; i++){
            if(list[i]!=0){
                cout<<name[i]<<"   :   Alive\n";
                zende++;
            }
        }
        cout<<"\nenter the results of voting\n";
        for(int i =0 ;i <zende ; i++){
            cin.getline (line,40);
            getdastoor(line,dastoor);
            hazfdastoor1(line,k);
            if(barabar(dastoor,vote)){
                getdastoor(k,votelist[i]);
                hazfdastoor(k,votenum[i]);
            }

        }
        cout<<"Are u sure ?     1)  yes    2)no\n";
        int a;cin>>a;
        if(a==2){
            cin.ignore();
            goto vote;

        }
        cout<<endl;
        int max=0;
        u=0;
        for( int i =0 ; i<zende;i++){//بزرگترین رای

             if(bozorgtary(votenum[i],votenum[max])){
                 max=i;
                 u=0;
             }
            if(barabar(votenum[i],votenum[max])){
                u++;
            }
        }
          if(u>1){//رای برابر
            shart:
            cout<<"\nequal vote :";
            for(int i=0 ; i <zende; i++)
                if(barabar(votenum[i],votenum[max]))
                    cout<<"   "<<votelist[i];
            cout<<endl<<"Enter votes of equals again  :  /n";
            cin.ignore();
            for(int i =0 ;i <u; i++){
                cin.getline (line,40);
                getdastoor(line,dastoor);
                hazfdastoor1(line,k);
                if(barabar(dastoor,vote)){
                    getdastoor(k,votelist[i]);
                    hazfdastoor(k,votenum[i]);
                }
            }
            max=0;
            int u1=0;
            for( int i =0 ; i<u;i++){//بزرگترین رای

                 if(bozorgtary(votenum[i],votenum[max])){
                     max=i;
                     u1=0;
                 }
                if(barabar(votenum[i],votenum[max])){
                    u1++;
                }
            };
            if(u1>1)
                goto shart;
        }
        //حذف فرد توسط رای گیری
        jabja(votelist[max],k);
        for(int i =0 ; i <n; i ++)
            if (barabar(k,name[i])){
                if(list[i]>(n-x1)){
                    x--;
                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }
                }
                if(list[i]>6 && list[i]<=(n-x1)){
                    m--;
                    zende--;
                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }
                }
                if(list[i]==1){
                    atashzan=false;
                    zende--;
                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }

                }
                if(list[i]==2){
                    ghatel=false;
                    zende--;
                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }

                }
                if(list[i]==3){
                    shekarchi=false;
                   x--;
                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }
                }
                if(list[i]==4){
                    elahe=false;

                    x--;
                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }
                }
                if(list[i]==5){
                    fereshte=false;
                    x--;

                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }
                }
                if(list[i]==6){
                    f--;

                    deathnaghsh[deathnumber]=list[i];
                    list[i]=0;
                    for(int c=0;c<2;c++)//love shart
                        if(barabar(k,lovelist[c])){
                            if(c){
                                jabja(lovelist[0],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                            else{
                                jabja(lovelist[1],k);
                                for(int y=0;y<n;y++)
                                    if(barabar(k,name[y])){
                                        if(list[y]==1)
                                            atashzan=false;
                                        if(list[y]==2)
                                            ghatel=false;
                                        if(list[y]==3){
                                            shekarchi=false;
                                            x--;
                                        }
                                        if(list[y]==4){
                                            elahe=false;
                                            x--;
                                        }
                                        if(list[y]==5){
                                            fereshte=false;
                                            x--;
                                        }
                                        if(list[y]==6)
                                            f--;
                                        if(list[y]>(n-x1))
                                            x--;
                                        if(list[y]>6 && list[i]<=(n-x1))
                                            m--;
                                        list[y]=0;
                                    }

                            }
                        }
                }
            }
        for(int i=0;i<n;i++){
            if(list[i]!=0)
                cout<<"\n  "<<name[i]<<"  : Alive"<<endl;
            else
                cout<<"\n "<<name[i]<<"   : dead"<<endl;
        }
        zende=0;
        for(int i =0 ;  i<n; i++){
            if(list[i]!=0){
                cout<<name[i]<<"   :   Alive\n";
                zende++;
            }
        }
        if(zende==x){
            cout<<"\n vilagers  win !";
            shart =false;
            break; }
        if((m==(zende /2) ||m>(zende/2))&& !atashzan &&! ghatel ){

            cout<<"\n wolves win !";
            shart =false;
            break;
        }
        if(f==zende){
            cout<<"\n Clut win";
            shart = false ;
            break;
        }

        }
    return 0 ;
}
