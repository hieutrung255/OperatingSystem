#include <iostream>
#include <time.h>

using namespace std;

//Khai báo biến toàn cục
int a = 5;
int currentThread = 0;
long long iValue = 2000000000; //lưu trữ giá trị số vòng lặp của các thread

// Hàm thực hiện chức năng của thread 1
void* thread1(void *pp){
    printf("Create thread A\n");
    int i = 0;
    while(i<iValue){
        if(currentThread != 0){
            cout<<"Hello thread1 "<<endl;
            currentThread = 0;
        }
        i++;
    }
    return NULL;
}

// Hàm thực hiện chức năng của thread 2
void* thread2(void *pp){

    printf("Create thread B\n");
    int i = 0;

    while(i<iValue){
        if(currentThread != 1){
            cout<<"Hello thread2"<<endl;
            currentThread = 1;
        }
        i++;
    }
    return NULL;
}

// Hàm thực hiện chức năng của thread 3
void* thread3(void *pp){
    printf("Create thread B\n");
    int i = 0;
    
    while(i<iValue){
        if(currentThread != 2){
            cout<<"Hello thread3"<<endl;
            currentThread = 2;
        }
        i++;
    }
    return NULL;
}

// Hàm thực hiện chức năng của thread 4
void* thread4(void *pp){
    printf("Create thread B\n");
    int i = 0;

    while(i<iValue){
        if(currentThread != 3){
            cout<<"Hello thread4"<<endl;
            currentThread = 3;
        }
        i++;
    }
    return NULL;
}

int main(int argc, char *argv[]){
    
    //Khởi tạo tham số pid cho threads
    pthread_t ppid1, ppid2, ppid3, ppid4;
    pthread_attr_t attr1, attr2, attr3, attr4;

    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);
    pthread_attr_init(&attr4);

    pthread_create(&ppid1, &attr1, thread1, NULL);
    pthread_create(&ppid2, &attr2, thread2, NULL);
    pthread_create(&ppid3, &attr3, thread3, NULL);
    pthread_create(&ppid4, &attr4, thread4, NULL);
  

    pthread_join(ppid1, NULL);
    pthread_join(ppid2, NULL);
    pthread_join(ppid3, NULL);
    pthread_join(ppid4, NULL);
    
    pthread_attr_destroy(&attr1);
    pthread_attr_destroy(&attr2);
    pthread_attr_destroy(&attr3);
    pthread_attr_destroy(&attr4);


    return 0;
    
}
