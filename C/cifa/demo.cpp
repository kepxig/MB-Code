#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
fprintf()
C 库函数 int fprintf(FILE *stream, const char *format, ...) 发送格式化输出到流 stream 中。
*/
char TOKEN[20];
char TABLE1[5][10] = {{"begin"},{"end"},{"if"},{"then"},{"else"}};
char TABLE2[6][3]={{"<"},{"<="},{"="},{"<>"},{">"},{">="}};
char TABLE3[1];

int lookup(char arr[]) {
    int i;
    for (int i = 0; i < 5; ++i) {
        if (!strcmp(arr,TABLE1[i]))
            return i+1;
    }
    return 0;
}
void out(int syn,char* token){
    FILE* wfp=fopen("output.txt","a+");
    fprintf(wfp,"(%d,%s)\n",syn,token);
    fclose(wfp);
}
// 扫描器
void scanner(FILE* fp) {
    //char ch, tmp;
    char ch;
    int i, c;
   // FILE* wfp = fopen("output.txt","w");

    while (ch != EOF) {	// 一次循环即扫描一个词 
        i = 0;
        ch = getc(fp);

        if (isalpha(ch)){   // 字母开头 
            TOKEN[i++] = ch;
            while (isalpha(ch=getc(fp))|| isdigit(ch)) {
                TOKEN[i++] = ch;
            }
            TOKEN[i] = '\0';
            fseek(fp,-1,1);
            c = lookup(TOKEN);
            if (c != 0)
            	//fprintf(wfp,"(%d,%s)\n",c,TOKEN);	// 关键字
                out(c,TOKEN); 
            else
                //fprintf(wfp,"(10,%s)\n",TOKEN);  // 标识符
                out(6,TOKEN);
        } else if (isdigit(ch)) {   // 数字开头 
            TOKEN[i++] = ch;
            while (isdigit(ch=getc(fp))) {
                TOKEN[i++] = ch;
            }
            TOKEN[i] = '\0';
            fseek(fp,-1,SEEK_CUR);
            //fprintf(wfp,"(20,%s)\n",TOKEN);    // 数字
            out(7,TOKEN);
        } else {    // 其它符号开头 
            switch (ch) {
                case ' ': break;
                case '\n': break;
                case '\t': break;
                case EOF: break;
                /*
                case '=': ch=getc(fp);
                    if (ch == '=') {
                    	fprintf(wfp,"(36,==)\n"); break;
					}
                    else {
                    	fprintf(wfp,"(21,=)\n"); break;
					} 
                
                case '+': fprintf(wfp,"(22,+)\n"); break;
                case '-': fprintf(wfp,"(23,-)\n"); break;
                case '*': fprintf(wfp,"(24,*)\n"); break;
                case '/': fprintf(wfp,"(25,/)\n"); break;
                case '(': fprintf(wfp,"(26,()\n"); break;
                case ')': fprintf(wfp,"(27,))\n"); break;
                case '{': fprintf(wfp,"(28,{)\n"); break;
                case '}': fprintf(wfp,"(29,})\n"); break;
                case ',': fprintf(wfp,"(30,,)\n"); break;
                case ';': fprintf(wfp,"(31,;)\n"); break;
                */
                case '=': out(10,TABLE2[2]);break;
                case '>': ch=fgetc(fp);
                    if (ch == '=') {
                    	//fprintf(wfp,"(34,>=)\n"); break;
                        out(13,TABLE2[5]);break;
					}
                    else {
                    	//fprintf(wfp,"(32,>)\n"); break;
                        out(12,TABLE2[4]);break;
					}
                case '<': ch=fgetc(fp);
                    if (ch == '=') {
                    	//fprintf(wfp,"(35,<=)\n"); break;
                        out(9,TABLE2[1]);break;
					}

                    else if(ch=='>'){
                        out(11,TABLE2[3]);break;
                    }

                    else {
                    	//fprintf(wfp,"(33,<)\n"); break;
                        out(8,TABLE2[0]);break;
					}
                /*
                case '!': tmp = ch;
					ch=getc(fp);
                    if(ch == '=')
					{
						fprintf(wfp,"(37,!=)\n"); 
						break;
					}
					else 
					{
						fprintf(wfp,"error:(0,%c)\n",tmp); 
						fseek(fp,-1,1);
						break;
					}
                */
                default:
                    //fprintf(wfp,"error:(0,%c)\n",ch); break;
                    TABLE3[0]=ch;
                    out(0,TABLE3);break;//0:undefined
            }
        }
    }
	//fclose(wfp); 
}

int main(){
    FILE* fp;
    char ch;
    if ((fp=fopen("test.txt","r")) == NULL){
        printf("文件打开错误！\n");
        return 0;
    }
    scanner(fp);
    fclose(fp);
    return 0;
}


