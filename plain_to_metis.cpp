#include <iostream>
#include "graph.h"
#include "plain.h"
#include "metis_graph.h"


/// usage: plain_to_metis <input_file> <output_file>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "usage: plain_to_metis <input_file> <output_file>\n";
        return 1;
    }
    std::string input_file(argv[1]), output_file(argv[2]);

    /* 输入数据需要保证顶点编号从 1 到 n 连续 */
    Graph g = load_plain(input_file);
    write_graph(g, output_file);
    return 0;
}
