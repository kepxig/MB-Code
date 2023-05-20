package mergesort;
import java.util.Arrays;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class ParallelMergeSort extends RecursiveAction {
    private final int[] array;
    private final int low;
    private final int high;

    public ParallelMergeSort(int[] array, int low, int high) {
        this.array = array;
        this.low = low;
        this.high = high;
    }

    protected void compute() {
        if (low < high) {
            if (high - low <= 1000) {
                // 对小数组使用串行归并排序
                Arrays.sort(array, low, high);
            } else {
                int mid = low + (high - low) / 2;
                // 将任务拆分为两个子任务并行执行
                invokeAll(new ParallelMergeSort(array, low, mid), new ParallelMergeSort(array, mid, high));
                // 合并排序后的子数组
                merge(array, low, mid, high);
            }
        }
    }

    private void merge(int[] array, int low, int mid, int high) {
        int[] left = Arrays.copyOfRange(array, low, mid);
        int[] right = Arrays.copyOfRange(array, mid, high);
        int i = 0, j = 0, k = low;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }
        while (i < left.length) {
            array[k++] = left[i++];
        }
        while (j < right.length) {
            array[k++] = right[j++];
        }
    }

    public static void main(String[] args) {
        int[] array = {9, 7, 5, 11, 12, 2, 14, 3, 6, 1, 8, 10, 4};
        
        System.out.println("Original Array: " + Arrays.toString(array));
        
        // 创建 ForkJoinPool 对象
        ForkJoinPool forkJoinPool = new ForkJoinPool();
        
        // 创建并行归并排序任务
        ParallelMergeSort mergeSort = new ParallelMergeSort(array, 0, array.length);
        
        // 执行任务
        forkJoinPool.invoke(mergeSort);
        
        // 打印排序结果
        System.out.println("Sorted Array: " + Arrays.toString(array));
    }
}