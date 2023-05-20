import java.util.LinkedList;
import java.util.Queue;

public class ProducerConsumer {
   public static void main(String[] args) {
      final Queue<Integer> sharedQueue = new LinkedList<Integer>();

      Thread producerThread = new Thread(new Producer(sharedQueue));
      Thread consumerThread = new Thread(new Consumer(sharedQueue));

      producerThread.start();
      consumerThread.start();
   }

   static class Producer implements Runnable {
      private final Queue<Integer> sharedQueue;

      public Producer(Queue<Integer> sharedQueue) {
         this.sharedQueue = sharedQueue;
      }

      @Override
      public void run() {
         for (int i = 1; i <= 10; i++) {
            synchronized (sharedQueue) {
               while (sharedQueue.size() >= 1) {
                  try {
                     sharedQueue.wait(); // 阻塞等待消费者消费
                  } catch (InterruptedException e) {
                     e.printStackTrace();
                  }
               }
               sharedQueue.add(i);
               System.out.println("生产者生产 : " + i);
               sharedQueue.notify(); // 通知消费者消费数据
            }
         }
      }
   }

   static class Consumer implements Runnable {
      private final Queue<Integer> sharedQueue;

      public Consumer(Queue<Integer> sharedQueue) {
         this.sharedQueue = sharedQueue;
      }

      @Override
      public void run() {
         while (true) {
            synchronized (sharedQueue) {
               while (sharedQueue.isEmpty()) {
                  try {
                     sharedQueue.wait(); // 阻塞等待生产者生产
                  } catch (InterruptedException e) {
                     e.printStackTrace();
                  }
               }
               int number = sharedQueue.poll();
               System.out.println("消费者消费 : " + number);
               sharedQueue.notify(); // 通知生产者生产数据
            }
         }
      }
   }
}
