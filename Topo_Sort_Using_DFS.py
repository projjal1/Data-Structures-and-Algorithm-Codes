class Solution:
    def topo_sort(self,node,stack,visited,d):
        #Set node as visited 
        visited[node]=1
        
        try:
            child_node=d[node]
        
            for var in child_node:
                if visited[var]==1:
                    continue
                else:
                    self.topo_sort(var,stack,visited,d)
        except:
            pass
        
        stack.append(node)
        
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        d=dict()
        for courses in prerequisites:
            y,x=courses
                            
            #Check for duplicacy by checking for mapping of x in list of y
            if (y in d) and (x in d[y]):
                return []
            else:
                if x not in d:
                    d[x]=[y]
                else:
                    d[x].append(y)
            
        visited=dict()
        stack=[]
        
        #Assigning to visited list
        for elems in range(numCourses):
            visited[elems]=0        
            
        for elems in range(numCourses):
            if visited[elems]==0:
                self.topo_sort(elems,stack,visited,d)
            else:
                continue
        
        return stack[::-1]