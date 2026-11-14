# OpenCV 图像处理算法练习（历史代码整理版）

这是早期学习 C++ / OpenCV 时编写的图像处理练习。最初为便于在同一个 `main.cpp` 中切换运行算法，将大部分练习整段注释。现把**每个算法单独整理成一个 `.cpp` 文件**，并恢复被整段注释的 C++ 语句。

## 整理范围

- **一个算法一个 `.cpp`**：所有练习平铺在 `src/`，不再使用章节文件夹。少量原文件存在“同一个函数切换不同核”“同一算法有多个接口”的情况，拆成各自的文件。
- **撤销整段注释**：让算法和 `main()` 不再仅以注释形式存在；原本用于说明原理、记录疑问、保留候选方案的注释继续保留。
- **头文件**：把被整段注释的 `#include` 恢复；缺少的依赖头文件仅做补充。
- **不修复逻辑错误**：保留原始算法的公式、索引、数据类型、参数及实验中的疑问；`未实现` / `未完成` 不会被改写。
- **无运行图**：没有添加图片、测试结果或运行截图。
- **原始副本**：`legacy/main.cpp` 与上传文件逐字节相同，可随时核对。

> **注意：** “取消整段注释”不代表原算法全部正确或所有文件都可以直接编译运行。旧代码中部分文件原本就有编译错误或运行时越界风险；本次按照原始性要求不修复。演示代码中的旧电脑绝对图片路径同样保留，不能直接保证在新环境运行。每个文件通常各有自己的 `main()`，**不要把所有 `.cpp` 直接链接成同一个可执行程序**。

## 目录

```text
opencv-practice/
├── README.md
├── src/                    # 每个算法一个 .cpp；不按章节建子目录
├── docs/
│   └── 算法索引.md           # 算法名称、文件名、原始行号对照
└── legacy/
    └── main.cpp            # 完整、未修改的原始文件
```

## 算法索引

### 基础图像操作

- [`mat_basics.cpp`](src/mat_basics.cpp)：OpenCV Mat 基础。Mat 对象、绘制圆形、图片读写、翻转、矩阵向量计算。
- [`roi_mask.cpp`](src/roi_mask.cpp)：ROI 区域与掩码复制。选取感兴趣区域（ROI），用掩码将 logo 拷贝到图像。

### 颜色与像素处理

- [`channel_swap.cpp`](src/channel_swap.cpp)：BGR 通道交换。按像素交换 B、G、R 三个通道。
- [`color_reduce.cpp`](src/color_reduce.cpp)：减色处理（逐像素访问）。按指定 div 量化像素颜色。
- [`bgr_to_gray.cpp`](src/bgr_to_gray.cpp)：BGR 转灰度。按原代码的通道权重转换灰度图。
- [`color_reduce_pointer.cpp`](src/color_reduce_pointer.cpp)：减色处理（行指针）。通过 Mat::ptr 按行读取像素实现减色。
- [`color_reduce_continuous.cpp`](src/color_reduce_continuous.cpp)：减色处理（连续内存）。检测 Mat 连续性并按行/连续内存进行像素处理。
- [`bgr_to_hsv.cpp`](src/bgr_to_hsv.cpp)：BGR 转 HSV。手动计算色相 H、饱和度 S、明度 V。
- [`hsv_to_bgr.cpp`](src/hsv_to_bgr.cpp)：HSV 转 BGR。手动将 HSV 转回 BGR（保留原代码未完成之处）。
- [`inverse_hue.cpp`](src/inverse_hue.cpp)：色相反转。将 H 色相分量旋转 180°。
- [`gamma_correction.cpp`](src/gamma_correction.cpp)：Gamma 校正。使用幂函数调整像素灰度或亮度。
- [`red_channel_reduce.cpp`](src/red_channel_reduce.cpp)：红色通道调整。按原代码减少红色通道的像素值。

### 二值化与直方图

- [`binary_threshold.cpp`](src/binary_threshold.cpp)：固定阈值二值化。灰度化后以固定阈值转换为黑白图。
- [`otsu_threshold.cpp`](src/otsu_threshold.cpp)：Otsu 大津二值化。枚举阈值并利用类间方差选择二值化阈值。
- [`histogram_normalization.cpp`](src/histogram_normalization.cpp)：直方图归一化。将原始像素范围线性映射到指定区间。
- [`histogram_equalization.cpp`](src/histogram_equalization.cpp)：直方图均衡化。统计像素频数并计算累计直方图。

### 边缘检测与锐化

- [`sharpen_3x3.cpp`](src/sharpen_3x3.cpp)：3×3 邻域锐化。使用中心像素及上下左右像素进行锐化。
- [`log_filter.cpp`](src/log_filter.cpp)：LoG（高斯-拉普拉斯）滤波。计算 LoG 核并进行卷积。
- [`roberts_gradient.cpp`](src/roberts_gradient.cpp)：Roberts 梯度算子。使用原文件中的 Roberts 梯度卷积核。
- [`roberts_cross.cpp`](src/roberts_cross.cpp)：Roberts 交叉梯度算子。使用原文件中的 Roberts 交叉梯度卷积核。
- [`prewitt.cpp`](src/prewitt.cpp)：Prewitt 算子。使用原文件中的 Prewitt 卷积核。
- [`emboss.cpp`](src/emboss.cpp)：Emboss 浮雕算子。使用原文件中的 Emboss 卷积核。
- [`sobel.cpp`](src/sobel.cpp)：Sobel 算子。使用两个方向的 Sobel 卷积核计算梯度。
- [`laplacian.cpp`](src/laplacian.cpp)：Laplacian 拉普拉斯滤波。使用拉普拉斯卷积核；保留原来搭配的归一化辅助函数。

### 插值与缩放

- [`nearest_neighbor.cpp`](src/nearest_neighbor.cpp)：最近邻插值。按照输出坐标查找距离最近的输入像素。
- [`bilinear_by_size.cpp`](src/bilinear_by_size.cpp)：双线性插值（目标尺寸）。目标图像尺寸作为参数，计算双线性插值。
- [`bilinear_by_scale.cpp`](src/bilinear_by_scale.cpp)：双线性插值（缩放系数）。缩放倍数 rx、ry 作为参数，计算双线性插值。
- [`reduce_resolution.cpp`](src/reduce_resolution.cpp)：降低图像分辨率。按照采样间隔缩小图像。
- [`bicubic.cpp`](src/bicubic.cpp)：双三次插值。用邻近 4×4 网格采样并计算双三次插值权重（原文未完成）。

### 池化与噪声

- [`average_pooling.cpp`](src/average_pooling.cpp)：平均池化。按照原代码对 8×8 邻域取平均值。
- [`max_pooling.cpp`](src/max_pooling.cpp)：最大池化。按照原代码对 8×8 邻域取最大值。
- [`salt_noise.cpp`](src/salt_noise.cpp)：盐噪声添加。随机将部分像素设为白色；保留原来的函数名 salt。

### 平滑与统计滤波

- [`median_filter.cpp`](src/median_filter.cpp)：中值滤波。将邻域像素排序并取中间值。
- [`mean_filter.cpp`](src/mean_filter.cpp)：均值滤波。计算方形邻域的算术平均值。
- [`max_filter.cpp`](src/max_filter.cpp)：最大值滤波。输出邻域灰度最大值。
- [`min_filter.cpp`](src/min_filter.cpp)：最小值滤波。输出邻域灰度最小值。
- [`gaussian_filter.cpp`](src/gaussian_filter.cpp)：高斯滤波。生成高斯卷积核并对像素做加权求和。

### 几何变换

- [`affine_translate_scale.cpp`](src/affine_translate_scale.cpp)：仿射平移与缩放。使用仿射矩阵参数完成平移和缩放实验。
- [`rotation.cpp`](src/rotation.cpp)：图像旋转。按角度构造仿射参数，进行坐标逆映射旋转。

## 代码阅读约定

1. 每个 `.cpp` 直接从 `#include` 和原有代码开始，不附加说明性文件头；算法名称、类别、功能及原始行号统一放在 README 和 `docs/算法索引.md` 中。
2. 各算法函数尽可能直接摘自原代码，仅去掉当年“整段关闭练习”的外层 `//`。
3. HSV 的三个方向、双线性插值的两个接口，需要从原来共用的演示入口分出各自的 `main()`；这是文件拆分所需的**演示入口调整**，不涉及算法计算逻辑修改。
4. Roberts 梯度、Roberts 交叉梯度、Prewitt 和 Emboss 原本共用 `filter()` 并通过切换卷积核练习；拆分后每个文件选用对应的**原始卷积核**，其余卷积处理代码沿用原文。
5. `laplacian.cpp` 保留了原示例中配套的 `histogram_normalization()` 辅助函数，避免改变原演示处理流程。
6. 如需查看原代码中其他被注释的备选语句和历史问题，可直接对照 `legacy/main.cpp`。

本版本是**学习代码整理存档**，不宣称已通过编译、运行或正确性测试。
