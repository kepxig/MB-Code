import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.datasets import load_iris

# 加载鸢尾花数据集
iris = load_iris()
X = iris.data[:, :2]  # 只使用前两个特征以便可视化
y = iris.target

# 使用K-means算法进行聚类，K=3
kmeans = KMeans(n_clusters=3, random_state=0)
kmeans.fit(X)
y_kmeans = kmeans.predict(X)

# 获取聚类中心
centers = kmeans.cluster_centers_

# 可视化聚类结果
plt.figure(figsize=(10, 6))

# 绘制数据点
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans, cmap='viridis', s=50)

# 绘制聚类中心
plt.scatter(centers[:, 0], centers[:, 1], c='red', s=200, alpha=0.75, marker='X')

# 添加标签
plt.xlabel('花萼长度')
plt.ylabel('花萼宽度')
plt.title('K-means聚类结果 (K=3)')

plt.show()