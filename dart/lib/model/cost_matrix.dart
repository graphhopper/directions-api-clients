part of swagger.api;

@Entity()
class CostMatrix {
  /* type of cost matrix, currently default or google are supported */
  @Property(name: 'type')
  String type = null;
  //enum typeEnum {  default,  google,  };
/* URL of matrix service */
  @Property(name: 'url')
  String url = null;
  

  @Property(name: 'location_ids')
  List<String> locationIds = [];
  

  @Property(name: 'data')
  CostMatrixData data = null;
  
/* vehicle profile or empty if catch all fallback */
  @Property(name: 'profile')
  String profile = null;
  
  CostMatrix();

  @override
  String toString()  {
    return 'CostMatrix[type=$type, url=$url, locationIds=$locationIds, data=$data, profile=$profile, ]';
  }
}

