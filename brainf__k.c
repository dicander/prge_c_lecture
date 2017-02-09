#include <stdio.h>
#include <stdlib.h>
static int dbg = 0;

//using namespace std;

int solve() {
    int memsize, codesize, inputsize;
    scanf("%d %d %d\n", &memsize, &codesize, &inputsize);
    char* raw_program = (char*)malloc(codesize*sizeof(char));
    char* input = (char*)malloc(inputsize*sizeof(char));
    scanf("%s\n", raw_program);
    scanf("%s\n", input);
    int codepos = 0;
    int inputpos = 0;
    int mempos = 0;
    char* memory = (char*) malloc(memsize*sizeof(char));
    for(int i=0; i<memsize; ++i) {
    memory[i] = 0U;
    }
    int* originalteleports = (int*) malloc(codesize*sizeof(int));
    int* teleports = (int*) malloc(codesize*sizeof(int));
    char* program = (char*)malloc(codesize*sizeof(char));
    int* s = (int*)malloc(codesize*sizeof(int));
    int* os = (int*)malloc(codesize*sizeof(int));
    int* convert = (int*)malloc(codesize*sizeof(int));
    int sp = 0;
    int osp = 0;
    int counter = 0;
    for(int i=0; i<codesize; ++i) {
        switch(raw_program[i]) {
            case '[':
                s[sp++]=codepos;
                os[osp++]=i;
                convert[codepos]=i;
                break;
            case ']':
                teleports[codepos]=s[--sp];
                teleports[teleports[codepos]] = codepos;
                originalteleports[i]=os[--osp];
                originalteleports[originalteleports[i]] = i;
                convert[codepos]=i;
                break;
            case '+':
            case '-':
                counter = 0;
                for(;i<codesize && (raw_program[i]=='-' || raw_program[i]=='+');++i) {
                    if(raw_program[i]=='+')teleports[codepos]++;
                    else teleports[codepos]--;
                    ++counter;
                }
                --i;
                raw_program[i]='+';
                convert[codepos]=counter;
                break;
        }
        program[codepos++]=raw_program[i];
    }
    codesize = codepos;
    codepos = 0;
    int loopstart = 0;
    int depth = 0;
    for(int i=0; i<50000000; ++i) {
        if(codepos >= codesize) {
            printf("Terminates\n");
            return 0;
        }
        if(program[codepos]=='[') {
            if(depth == 0) {
        loopstart = codepos;
        }
        depth++;
        }
        switch(program[codepos]) {
            case '+':
                memory[mempos]+=teleports[codepos]; break;
                i+=counter;
            case '>':
                mempos=(mempos+1)%memsize;break;
            case '<':
                mempos=(mempos+memsize-1)%memsize;break;
            case ',':
                memory[mempos] = (inputpos>=inputsize)?255:input[inputpos];
                ++inputpos;
                break;
            //case '.':
            //    if(dbg){printf("%c",(char)memory[mempos]);fflush(stdout);};break;
            case '[':
                codepos = (memory[mempos]==0U)?teleports[codepos]:codepos;break;
            case ']':
                codepos = (memory[mempos]>0U)?teleports[codepos]:codepos;break;
        }
        if(program[codepos] == ']') {
            --depth;
        }
        ++codepos;
    }
    codepos = convert[loopstart];
    printf("Loops %d %d\n", codepos, originalteleports[codepos]);
    free(teleports);
    free(raw_program);
    free(originalteleports);
    free(program);
    return 0;
}

int main() {
    int n;
    scanf("%d\n", &n);
    for(int i=0; i<n; ++i) {
        solve();
    }
    fflush(stdout);
    return 0;
}
