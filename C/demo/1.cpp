#define PRODUCER 4      //����������
#define CONSUMER 4      //����������
#define BUFFER 8        //��������С
int producer_id = 0;	
int consumer_id = 0;
int in = 0;
int out = 0;
int Buffer[BUFFER];
sem_t sem_empty;              //ͬ���ź���
sem_t sem_full;
pthread_mutex_t mutex;        //�����ź���

void Signal_print();          //�����ź�
void print();                 //��ӡ�������
void *producer();             //������
void *consumer();             //������

void *producer(){
    int id = ++producer_id;

    while(1){
        sleep(3);                       //�����ٶ�

        sem_wait(&sem_empty);           //p(empty)����
        pthread_mutex_lock(&mutex);     //p(mutex)����

        in %= BUFFER;
        printf("������%d����Ʒ���뻺�������е�%d��      ",id,in+1);
        Buffer[in] = 1;
        print();
        ++in;

        pthread_mutex_unlock(&mutex);   //v(mutex)����
        sem_post(&sem_full);            //v(full)����

    }
}
void *consumer(){
    int id = ++consumer_id;

    while(1){
        sleep(3);

        sem_wait(&sem_full);
        pthread_mutex_lock(&mutex);

        out %= BUFFER;
        printf("������%d�ӻ��������е�%d��ȡ�߲�Ʒ      ",id,out+1);
        Buffer[out] = 0;
        print();
        ++out;

        pthread_mutex_unlock(&mutex);
        sem_post(&sem_empty);
    }
}
