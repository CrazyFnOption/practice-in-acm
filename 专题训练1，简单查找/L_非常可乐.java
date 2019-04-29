import java.util.*;

public class L_非常可乐 {

    static Scanner in = new Scanner(System.in);

    static final int maxn = 105;
    // 标志数组来标记路径，三个杯子三维数组即可
    static int[][][] visited = new int[maxn][maxn][maxn];

    static void init() {
        for (int i = 0; i < maxn; ++i)
            for (int j = 0; j < maxn; ++j)
                for (int k = 0; k < maxn; ++k)
                    visited[i][j][k] = 0;
    }

    // a b c为三个容器的最大容量
    static void bfs(int a, int b, int c) {
        if (a % 2 == 1) {
            System.out.println("NO");
            return;
        }
        //记住这里可以直接写queue的接口 来声明类型 并且在后面 new 的时候 以LinkedList来实现 其的接口
        Queue<Node> que = new LinkedList<Node>();
        // 初始
        que.add(new Node(a, 0, 0, 0));
        while (!que.isEmpty()) {
            // 取队头并弹出
            Node t = que.poll();
            visited[t.a][t.b][t.c] = 1;
            // 判断是否符合条件
            if (t.a == t.b && t.c == 0 || t.a == t.c && t.b == 0 || t.b == t.c && t.a == 0) {
                System.out.println(t.step);
                return;
            }

            // 倒水过程，注意倒水的前提是杯子里面有水
            // b -> a
            if (t.b != 0) {
                // 因为没有刻度， 所以每次倒水都有两种情况
                // 第一种情况是把自己倒完
                if (t.a + t.b <= a) {
                    if (visited[t.a + t.b][0][t.c] == 0) {
                        que.add(new Node(t.a + t.b, 0, t.c, t.step + 1));
                        visited[t.a + t.b][0][t.c] = 1;
                    }
                }
                // 第二种情况是把对方倒满
                else if (t.a != a) {
                    if (visited[a][t.b - (a - t.a)][t.c] == 0) {
                        que.add(new Node(a, t.b - (a - t.a), t.c, t.step + 1));
                        visited[a][t.b - (a - t.a)][t.c] = 1;
                    }
                }
            }

            // c -> a
            if (t.c != 0) {
                if (t.a + t.c <= a) {
                    if (visited[t.a + t.c][t.b][0] == 0) {
                        que.add(new Node(t.a + t.c, t.b, 0, t.step + 1));
                        visited[t.a + t.c][t.b][0] = 1;
                    }
                } else if (t.a != a) {
                    if (visited[a][t.b][t.c - (a - t.a)] == 0) {
                        que.add(new Node(a, t.b, t.c - (a - t.a), t.step + 1));
                        visited[a][t.b][t.c - (a - t.a)] = 1;
                    }
                }
            }

            // b -> c
            if (t.b != 0) {
                if (t.b + t.c <= c) {
                    if (visited[t.a][0][t.b + t.c] == 0) {
                        que.add(new Node(t.a, 0, t.b + t.c, t.step + 1));
                        visited[t.a][0][t.b + t.c] = 1;
                    }
                } else if (t.c != c) {
                    if (visited[t.a][t.b - (c - t.c)][c] == 0) {
                        que.add(new Node(t.a, t.b - (c - t.c), c, t.step + 1));
                        visited[t.a][t.b - (c - t.c)][c] = 1;
                    }
                }
            }

            // c -> b
            if (t.c != 0) {
                if (t.c + t.b <= b) {
                    if (visited[t.a][t.c + t.b][0] == 0) {
                        que.add(new Node(t.a, t.c + t.b, 0, t.step + 1));
                        visited[t.a][t.c + t.b][0] = 1;
                    }
                } else if (t.b != b) {
                    if (visited[t.a][b][t.c - (b - t.b)] == 0) {
                        que.add(new Node(t.a, b, t.c - (b - t.b), t.step + 1));
                        visited[t.a][b][t.c - (b - t.b)] = 1;
                    }
                }
            }

            // a -> b
            if (t.a != 0) {
                if (t.a + t.b <= b) {
                    if (visited[0][t.a + t.b][t.c] == 0) {
                        que.add(new Node(0, t.a + t.b, t.c, t.step + 1));
                        visited[0][t.a + t.b][t.c] = 1;
                    }
                } else if (t.b != b) {
                    if (visited[t.a - (b - t.b)][b][t.c] == 0) {
                        que.add(new Node(t.a - (b - t.b), b, t.c, t.step + 1));
                        visited[t.a - (b - t.b)][b][t.c] = 1;
                    }
                }
            }

            // a -> c
            if (t.a != 0) {
                if (t.a + t.c <= c) {
                    if (visited[0][t.b][t.a + t.c] == 0) {
                        que.add(new Node(0, t.b, t.a + t.c, t.step + 1));
                        visited[0][t.b][t.a + t.c] = 1;
                    }
                } else if (t.c != c) {
                    if (visited[t.a - (c - t.c)][t.b][c] == 0) {
                        que.add(new Node(t.a - (c - t.c), t.b, c, t.step + 1));
                        visited[t.a - (c - t.c)][t.b][c] = 1;
                    }
                }
            }

        }
        System.out.println("NO");
    }

    public static void main(String[] args) {

        while (in.hasNext()) {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            if (a == 0 && b == 0 && c == 0)
                break;
            init();
            bfs(a, b, c);
        }
    }

}

class Node {
    // a b c 代表实际拥有水的体积
    int a, b, c, step;

    Node(int a, int b, int c, int step) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.step = step;
    }
}
