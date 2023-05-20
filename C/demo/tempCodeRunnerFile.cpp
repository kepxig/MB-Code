#define PRODUCER 4      //生产者数量
#define CONSUMER 4      //消费者数量
#define BUFFER 8        //缓冲区大小
int producer_id = 0;	
int consumer_id = 0;
int in = 0;
int out = 0;
int Buffer[BUFFER];
sem_t sem_empty;              //同步信号量
sem_t sem_full;
pthread_mutex_t mutex;        //互斥信号量

void Signal_print();          //处理信号
void print();                 //打印缓冲队列
void *producer();             //生产者
void *consumer();             //消费者

void *producer(){
    int id = ++producer_id;

    while(1){
        sleep(3);                       //调节速度

        sem_wait(&sem_empty);           //p(empty)操作
        pthread_mutex_lock(&mutex);     //p(mutex)操作

        in %= BUFFER;
        printf("生产者%d将产品放入缓冲区队列第%d号      ",id,in+1);
        Buffer[in] = 1;
        print();
        ++in;

        pthread_mutex_unlock(&mutex);   //v(mutex)操作
        sem_post(&sem_full);            //v(full)操作

    }
}
void *consumer(){
    int id = ++consumer_id;

    while(1){
        sleep(3);

        sem_wait(&sem_full);
        pthread_mutex_lock(&mutex);

        out %= BUFFER;
        printf("消费者%d从缓冲区队列第%d号取走产品      ",id,out+1);
        Buffer[out] = 0;
        print();
        ++out;

        pthread_mutex_unlock(&mutex);
        sem_post(&sem_empty);
    }
}
