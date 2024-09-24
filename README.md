# 格式转换工具

这是一个使用 C++ 编写的文件格式转换工具。可以实现 [challenge9](https://www.diag.uniroma1.it//challenge9/download.shtml) 提供的文件格式（称为 plain 格式），
与 [METIS](https://github.com/DMA-Lab/METIS) 读、写的图格式（称为 metis 格式）互转。
注意，这两类图均要求顶点编号从 1~n 连续。

这个工具是作者在使用 METIS 时顺手编写的。METIS 支持的功能很多，目前，这个项目只支持普通图的输入与输出。请参考 METIS 5.1.x Manual 中
Input file formats 和 Output file formats 两节。

## 使用方式

plain 格式转 metis 格式：

```shell
convert_to_metis_file "USA-road-t.NY.gr" "USA-road-t.NY.metis.gr"
```