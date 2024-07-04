# algebra
<br>

## 实现思路 | Thinking

1. `add_matrix`、`sub_matrix`、`mul_matrix`、`scale_matrix`、`transpose_matrix`、`trace_matrix` 等函数较容易实现；
2. `det_matrix`、`inv_matrix` 难度稍微提高，实现中才用了 `Thinking.md` 中递归的思路，不过我认为 `Thinking.md` 中建议 `a.rows = a.cols = 2` 作为分类的标准有局限性，所以在实现中改为了 `a.rows = a.cols = 1` 作为递归出口；
3. `rank_matrix` 主要采用高斯消元法的思想，代码实现较为繁琐，主要分为**行交换**和**消元**两部分，维护阶梯型矩阵；为了实现本功能，另外写了两个函数 `create_submatrix` 用来实现低一维矩阵，`swap_rows` 用来实现行的交换。

<br>

## 本地运行截图 | Screenshot

> 截图采用了绝对引用的方式，截图原图像保存在 `assets` 文件夹中。

### 0. Running

---

![Running](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\Running.png)


### 1. add_matrix
---

![add_matrix](.\assets\add_matrix.png)
### 2. sub_matrix
---
![sub_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\sub_matrix.png)

### 3.  mul_matrix
---
![mul_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\mul_matrix.png)

### 4.  scale_matrix
---
![scale_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\scale_matrix.png)

### 5.  transpose_matrix
---
![transpose_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\transpose_matrix.png)

### 6.  det_matrix
---
![det_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\det_matrix.png)
### 7.  inv_matrix
---
![inv_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\inv_matrix.png)

### 8.  rank_matrix
---
![rank_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\rank_matrix.png)

### 9.  trace_matrix
---
![trace_matrix](D:\ZJU\TrainingCamp\01_BasicProgramming\HeZijue_HW1\assets\trace_matrix.png)





