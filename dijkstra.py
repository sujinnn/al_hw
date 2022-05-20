import heapq


graph = {
    'A': {'B': 5, 'D': 2, 'E': 4},
    'B': {'A': 5, 'C': 3, 'D': 3},
    'C': {'B': 3, 'D': 3, 'E': 4, 'F': 2},
    'D': {'A': 2, 'B': 3, 'C': 3, 'E': 1},
    'E': {'A': 4, 'C': 4, 'D': 1, 'F': 2},
    'F': {'C': 2, 'E': 2}
}

def dijkstra(graph, start):
    distance = {node: float('inf') for node in graph}
    distance[start] = 0
    queue = []
    #queue에 거리, 노드 값을 넣음
    heapq.heappush(queue, [distance[start], start])

    while queue:
        #가장 작은 값인 노드와 거리
        now_distance, now_node = heapq.heappop(queue)

        for new_node, new_distance in graph[now_node].items():
            #주변 node를 지나는 거리를 더함
            total_distance = now_distance + new_distance

            #기존 값보다 주변 node를 지난 거리가 짧을 경우 더 작은 값으로 변경
            if total_distance < distance[new_node]:
                distance[new_node] = total_distance
                heapq.heappush(queue, [total_distance, new_node])

    print("기준 node가",start,"일 때: ",distance)


dijkstra(graph,"A")
dijkstra(graph, "B")