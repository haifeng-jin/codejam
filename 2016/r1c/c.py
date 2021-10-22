import networkx as nx

def solve():
    n = int(input())
    topics = [(input().split()) for i in range(n)]
    topics = list(map(lambda pair: ('0' + pair[0], '1' + pair[1]), topics))
    first_words = set(map(lambda topic: topic[0], topics))
    second_words = set(map(lambda topic: topic[1], topics))
    graph = nx.Graph()
    graph.add_nodes_from(first_words, bipartite=0)
    graph.add_nodes_from(second_words, bipartite=1)
    graph.add_edges_from(topics)
    return len(topics) - (len(first_words) + len(second_words) -
len(nx.bipartite.maximum_matching(graph)) / 2)
        

for case in range(int(input())):
    print('Case #%d: %d' % (case + 1, solve()))
