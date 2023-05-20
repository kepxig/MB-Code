// 导入相关库
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class Main {
public static void main(String[] args) {

    // 创建一个线程不安全的 HashMap
    Map<String, String> hashMap = new HashMap<>();

    // 向 hashMap 中添加数据
    hashMap.put("apple", "red");
    hashMap.put("banana", "yellow");
    hashMap.put("kiwi", "green");

    // 使用 Collections.synchronizedMap(Map<K,V> m) 包装 hashMap
    Map<String, String> synchronizedMap = Collections.synchronizedMap(hashMap);

    // 创建一个线程安全的 ConcurrentHashMap
    ConcurrentHashMap<String, String> concurrentHashMap = new ConcurrentHashMap<>();

    // 向 concurrentHashMap 中添加数据
    concurrentHashMap.put("apple", "red");
    concurrentHashMap.put("banana", "yellow");
    concurrentHashMap.put("kiwi", "green");

    // 输出 ConcurrentHashMap 的大小
    System.out.println("ConcurrentHashMap size: " + concurrentHashMap.size());
}
}