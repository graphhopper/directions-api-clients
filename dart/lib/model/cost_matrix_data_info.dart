part of swagger.api;

@Entity()
class CostMatrixDataInfo {
  
  @Property(name: 'copyrights')
  List<String> copyrights = [];
  

  @Property(name: 'took')
  double took = null;
  
  CostMatrixDataInfo();

  @override
  String toString()  {
    return 'CostMatrixDataInfo[copyrights=$copyrights, took=$took, ]';
  }
}

