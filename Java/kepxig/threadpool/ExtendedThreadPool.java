import java.util.concurrent.*;

public class ExtendedThreadPool extends ThreadPoolExecutor {

    public ExtendedThreadPool(int corePoolSize, int maximumPoolSize, long keepAliveTime, TimeUnit unit,
                          BlockingQueue<Runnable> workQueue, ThreadFactory threadFactory) {
        super(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory);
    }

    @Override
    protected void beforeExecute(Thread t, Runnable r) {
        System.out.println("Thread " + t.getName() + " starts executing task " + r.toString());
        super.beforeExecute(t, r);
    }

    @Override
    protected void afterExecute(Runnable r, Throwable t) {
        System.out.println("Task " + r.toString() + " finishes executing.");
        super.afterExecute(r, t);
    }

    @Override
    protected void terminated() {
        System.out.println("Thread pool terminated.");
        super.terminated();
    }

    public static void main(String[] args) {
        // 创建一个线程池，并指定初始大小为2，最大大小为4，空闲线程存活时间为5秒
        ExecutorService executorService = new ExtendedThreadPool(2, 4,
                5L, TimeUnit.SECONDS, new ArrayBlockingQueue<>(4), Executors.defaultThreadFactory());

        // 提交任务
        for (int i = 0; i < 8; i++) {
            executorService.execute(() -> {
                System.out.println(Thread.currentThread().getName() + " executing task");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            });
        }

        // 关闭线程池
        executorService.shutdown();
    }
}
