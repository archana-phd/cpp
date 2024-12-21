Calculation Graph
•	A directed structure where each node represents either:
o	A pure, side-effect-free calculation, which depends on inputs (other nodes).
o	A constant or fixed value, serving as a standalone node with no dependencies.
•	Dependencies are represented as directed edges between nodes.
•	Acts as a Dependency Graph, showing how calculations and constants interact.
•	Must form a Directed Acyclic Graph (DAG) to avoid circular dependencies and ensure computability.
Advantages
•	Caching for Performance: Results of nodes can be cached, avoiding redundant recalculations.
o	Especially when particular nodes are shared by multiple others, its result is reused, enhancing speed. Example: implied volatility can be reused by both swap and option products.
•	Quick "What-If" Analysis: Changing one or more leaf nodes (inputs) allows efficient recalculation, as only affected nodes need reevaluation.
o	Example: Bump-and-reprice risk calculations for financial instruments benefit from this efficiency.
•	Dependency Tracing: Enables determination of all dependencies of any node by traversing its dependent nodes.
o	Example: Identifying all market data required to price a swap or an option.
