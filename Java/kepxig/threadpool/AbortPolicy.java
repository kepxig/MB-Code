
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class AbortPolicy {

    public static void main(String[] args) {
    
        // 创建一个固定大小的线程池
        ExecutorService executor = Executors.newFixedThreadPool(5);

        // 将线程池强制转换为 ThreadPoolExecutor 类型
        ThreadPoolExecutor threadPoolExecutor = (ThreadPoolExecutor) executor;

        // 设置线程池的拒绝策略为 AbortPolicy 策略
        threadPoolExecutor.setRejectedExecutionHandler(new ThreadPoolExecutor.AbortPolicy());

        // 执行任务
        for (int i = 0; i < 10; i++) {
            executor.execute(new Task("Task " + i));
        }

        // 关闭线程池
        executor.shutdown();
    }

    // 自定义任务类
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

    
