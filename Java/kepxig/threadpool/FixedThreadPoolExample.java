/*�ڸ�ʾ���У��������ȶ�����һ���߳�������Ȼ��ͨ��Executors����������newFixedThreadPool()������һ���̶��߳��������̳߳ء�
Ȼ��ͨ��ѭ���ύ����ÿ��������һ��ʵ����Runnable�ӿڵ��Զ����ࡣÿ���̳߳��е��̻߳᲻�ϵش����������ȡ������ִ�С�
���ͨ��shutdown()�����ر����̳߳ء�*/

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FixedThreadPoolExample {
    public static void main(String[] args) {
        int threadCount = 5; // �����߳�����
        ExecutorService executor = Executors.newFixedThreadPool(threadCount); // �����̳߳�
        for (int i = 0; i < 10; i++) { // ͨ��ѭ���ύ����
            executor.submit(new Task(i));
        }
        executor.shutdown(); // �ر��̳߳�
    }
    
    // �Զ���������
    private static class Task implements Runnable {
        private int taskId;
        
        public Task(int taskId) {
            this.taskId = taskId;
        }
        
        @Override
        public void run() {
            System.out.println("Task " + taskId + " is running on thread " + Thread.currentThread().getName());
        }
    }
}
