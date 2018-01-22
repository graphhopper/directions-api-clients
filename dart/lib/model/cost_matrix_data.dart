part of swagger.api;

@Entity()
class CostMatrixData {
  
  @Property(name: 'times')
  List<List<int>> times = [];
  

  @Property(name: 'distances')
  List<List<double>> distances = [];
  

  @Property(name: 'info')
  CostMatrixDataInfo info = null;
  
  CostMatrixData();

  @override
  String toString()  {
    return 'CostMatrixData[times=$times, distances=$distances, info=$info, ]';
  }
}

