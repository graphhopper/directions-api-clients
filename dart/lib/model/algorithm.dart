part of swagger.api;

@Entity()
class Algorithm {
  
  @Property(name: 'problem_type')
  String problemType = null;
  //enum problemTypeEnum {  min,  min-max,  };

  @Property(name: 'objective')
  String objective = null;
  //enum objectiveEnum {  transport_time,  completion_time,  };
  Algorithm();

  @override
  String toString()  {
    return 'Algorithm[problemType=$problemType, objective=$objective, ]';
  }
}

