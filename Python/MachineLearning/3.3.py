# 导入库
from sklearn.datasets import load_iris
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split

# 加载鸢尾花数据集
iris = load_iris()
X = iris.data
y = iris.target

# 随机划分数据集为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# 创建GaussianNB模型
gnb = GaussianNB()

# 训练模型
gnb.fit(X_train, y_train)

# 预测测试数据
y_pred = gnb.predict(X_test)

# 计算准确率
accuracy = (y_pred == y_test).mean()
print("分类预测的准确率:", accuracy)