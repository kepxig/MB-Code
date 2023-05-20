/*在该示例中，我们首先定义了一个线程数量，然后通过Executors工厂方法的newFixedThreadPool()创建了一个固定线程数量的线程池。
然后通过循环提交任务，每个任务是一个实现了Runnable接口的自定义类。每个线程池中的线程会不断地从任务队列中取出任务执行。
最后通过shutdown()方法关闭了线程池。*/

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FixedThreadPoolExample {
    public static void main(String[] args) {
        int threadCount = 5; // 定义线程数量
        ExecutorService executor = Executors.newFixedThreadPool(threadCount); // 创建线程池
        for (int i = 0; i < 10; i++) { // 通过循环提交任务
            executor.submit(new Task(i));
        }
        executor.shutdown(); // 关闭线程池
    }
    
    // 自定义任务类
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
