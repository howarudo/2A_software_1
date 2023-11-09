#include <stdio.h>
#include <stdlib.h>

int hokuriku_checker(char *name_list);

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if(hokuriku_checker(argv[i]) == 1) {
            printf("hokurkiku jan!");
        }
    }
}

int hokuriku_checker(char *name) {

}
