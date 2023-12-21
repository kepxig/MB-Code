import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# 生成不同分散程度的数据集
X1 = np.random.randn(100, 2)
X2 = np.random.randn(100, 2) * 0.5 + [2, 2]
X = np.concatenate([X1, X2])

# 使用K-means算法
kmeans_data_dispersion = KMeans(n_clusters=2, random_state=0)
kmeans_data_dispersion.fit(X)
y_kmeans_data_dispersion = kmeans_data_dispersion.predict(X)

# 可视化聚类结果
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans_data_dispersion, cmap='viridis')
centers = kmeans_data_dispersion.cluster_centers_
plt.scatter(centers[:, 0], centers[:, 1], c='red', s=200, alpha=0.75)
plt.title("不同数据分散程度的K-means聚类结果")
plt.show()