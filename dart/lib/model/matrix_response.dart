part of swagger.api;

@Entity()
class MatrixResponse {
  
  @Property(name: 'distances')
  List<List<num>> distances = [];
  

  @Property(name: 'times')
  List<List<num>> times = [];
  

  @Property(name: 'weights')
  List<List<double>> weights = [];
  

  @Property(name: 'info')
  ResponseInfo info = null;
  
  MatrixResponse();

  @override
  String toString()  {
    return 'MatrixResponse[distances=$distances, times=$times, weights=$weights, info=$info, ]';
  }
}

