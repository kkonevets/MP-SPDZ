from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

from torch import nn

import numpy as np


def get_ordinary_data():
    X, y = datasets.make_classification(
        n_samples=50,
        n_features=4,
        n_informative=3,
        n_redundant=1,
        n_repeated=0,
        n_classes=2,
        random_state=43,
    )

    X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=43)

    sc = StandardScaler()
    sc.fit(X_train)

    X_train = sc.transform(X_train)
    X_test = sc.transform(X_test)

    return X_train, X_test, y_train, y_test


def get_model(X_train, y_train):
    input_dim = X_train.shape[1]
    output_dim = len(np.unique(y_train))

    return nn.Sequential(
        nn.Linear(input_dim, output_dim),
    )
