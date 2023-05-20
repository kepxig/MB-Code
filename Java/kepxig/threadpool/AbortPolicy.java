
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class AbortPolicy {

    public static void main(String[] args) {
    
        // ����һ���̶���С���̳߳�
        ExecutorService executor = Executors.newFixedThreadPool(5);

        // ���̳߳�ǿ��ת��Ϊ ThreadPoolExecutor ����
        ThreadPoolExecutor threadPoolExecutor = (ThreadPoolExecutor) executor;

        // �����̳߳صľܾ�����Ϊ AbortPolicy ����
        threadPoolExecutor.setRejectedExecutionHandler(new ThreadPoolExecutor.AbortPolicy());

        // ִ������
        for (int i = 0; i < 10; i++) {
            executor.execute(new Task("Task " + i));
        }

        // �ر��̳߳�
        executor.shutdown();
    }

    // �Զ���������
    static class Task implements Runnable {
        private String name;

        public Task(String name) {
            this.name = name;
        }

        @Override
        public void run() {
            try {
                System.out.println("Thread " + Thread.currentThread().getName() + " is running " + name);
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

    
