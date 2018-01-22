part of swagger.api;

@Entity()
class ResponseInfo {
  
  @Property(name: 'copyrights')
  List<String> copyrights = [];
  

  @Property(name: 'took')
  double took = null;
  
  ResponseInfo();

  @override
  String toString()  {
    return 'ResponseInfo[copyrights=$copyrights, took=$took, ]';
  }
}

