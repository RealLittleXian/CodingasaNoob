import torch.nn as nn
import torch.nn.functional as F


class Model1(nn.Module):

    def __init__(self):
        super().__init__()

    def forward(self, x):
        return x + 1


class Model2(nn.Module):

    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d()
        self.conv2 = nn.Conv2d()

    def forward(self, x):
        x = F.relu(self.conv1(x))
        return F.relu(self.conv2(x))


model1 = Model1()

x = 1

print(model1(x))
