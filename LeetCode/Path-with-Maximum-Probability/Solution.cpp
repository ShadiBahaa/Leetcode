class Solution {
        Map<Integer, List<Pair<Integer, Double>>> adjList = new HashMap<>();
        Double[] memo;
        boolean[] visited;

        public double maxProbability(int n, int[][] edges, double[] prob, int src, int dest) {
            this.memo = new Double[n]; this.visited = new boolean[n];
            for(int i = 0; i < edges.length; i++) {
                var edge = edges[i]; double p = prob[i];
                adjList.computeIfAbsent(edge[0], ArrayList::new).add(new Pair<>(edge[1], p));
                adjList.computeIfAbsent(edge[1], ArrayList::new).add(new Pair<>(edge[0], p));
            }

            return dfs(src, dest);
        }

        double dfs(int src, int dest) {
            if(src == dest) return 1d;
            if (memo[src] != null) return memo[src];
            if(visited[src]) return 0d; // 0 if can't reach dest

            visited[src] = true;

            double maxProb = 0d;
            for(var neiProb : adjList.getOrDefault(src, List.of())) {
                int nei = neiProb.getKey(); double prob = neiProb.getValue();
                maxProb = Math.max(maxProb, prob * dfs(nei, dest));
            }

            return memo[src] = maxProb;
        }
    }