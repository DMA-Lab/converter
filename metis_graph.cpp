
#include <fstream>
#include <format>
#include <cstring>
#include <iterator>
#include "graph.h"
#include "metis_graph.h"


void write_graph(const Graph &g, const std::string &path) {
    ofstream file(path);
    if (!file) {
        throw std::runtime_error(std::format("can't open file {}: {}\n", path, std::strerror(errno)));
    }

    file << g.vertex_count << " " << g.edge_count << " 001" << std::endl;

    for (auto v_i = 1; v_i <= g.vertex_count; ++v_i) {
        for (auto [v_j, w]: g.get_adjacent_vertices(v_i)) {
            file << v_j << " " << w << " ";
        }
        file << std::endl;
    }
    file.close();
}
