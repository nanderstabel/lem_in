# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    visualizer.py                                      :+:    :+:             #
#                                                      +:+                     #
#    By: nstabel <nstabel@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/20 20:30:03 by nstabel        #+#    #+#                 #
#    Updated: 2020/03/20 20:30:03 by nstabel       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import networkx as nx


G = nx.read_edgelist("edges", nodetype = str, data = (('color', str),))
G = G.to_directed()
pos = nx.kamada_kawai_layout(G)
print(pos['Y_m5'][0])
edgecolors = []
for (u, v, c) in G.edges.data('color', default='blue'):
	edgecolors.append(c)
nodecolors = []
for (n, c) in G.nodes.data('color', default='red'):
	if n == 'Fog1' or n == 'Gll7':
		c = 'yellow'
	nodecolors.append(c)
	
nx.draw(G, pos, edge_color=edgecolors, node_color=nodecolors, with_labels=True)

plt.show()

