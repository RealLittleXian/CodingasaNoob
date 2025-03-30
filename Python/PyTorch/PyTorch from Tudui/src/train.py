import torch
import torchvision
from torch.utils.data import DataLoader

from model import *
from torch.utils.tensorboard import SummaryWriter
writer = SummaryWriter("D:/Coding/logs")


train_data = torchvision.datasets.CIFAR10(
    root="D:/Coding/datasets",
    train=True,
    transform=torchvision.transforms.ToTensor(),
    download=True,
)

test_data = torchvision.datasets.CIFAR10(
    root="D:/Coding/datasets",
    train=True,
    transform=torchvision.transforms.ToTensor(),
    download=True,
)

train_data_size = len(train_data)
test_data_size = len(test_data)

print("train_data_size = {}".format(train_data_size))
print("test_data_size = {}".format(test_data_size))

train_dataloader = DataLoader(dataset=train_data, batch_size=64)
test_dataloader = DataLoader(dataset=test_data, batch_size=64)

# build model
model = NerualNetwork()

# define loss function
loss_function = nn.CrossEntropyLoss()

# define optimizer
lr = 0.01
optimizer = torch.optim.SGD(model.parameters(), lr=lr)

train_step = 0
test_step = 0
epoch = 10

for i in range(epoch):
    print("epoch {}".format(i + 1))
    model.train()
    for data in train_dataloader:
        imgs, targets = data
        output = model(imgs)
        loss = loss_function(output, targets)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        train_step += 1
        if train_step % 100 == 0:
            print("total train step: {} , loss: {} ".format(train_step, loss))
            writer.add_scalar("train_loss", loss.item(), train_step)
            
    model.eval()
    total_test_loss = 0
    total_accuracy = 0
    with torch.no_grad():
        for data in test_dataloader:
            imgs, targets = data
            output = model(imgs)
            loss = loss_function(output, targets)
            accuracy = (output.argmax(1) == targets).sum()
            total_test_loss += loss
            total_accuracy += accuracy
            
    print("total test loss: {}".format(total_test_loss))
    print("total accuracy: {}".format(total_accuracy / test_data_size))
    writer.add_scalar("test_loss", total_test_loss, test_step)
    writer.add_scalar("test_accuracy", total_accuracy / test_data_size, test_step)
    test_step += 1
    total_accuracy += 1
    
    torch.save(model, "D:/Coding/models/model.pth")
    # torch.save(model.state_dict(), "D:/Coding/models/model_state_dict.pth")
    print("saved")
        
writer.close()