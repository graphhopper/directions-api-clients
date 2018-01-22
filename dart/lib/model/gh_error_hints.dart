part of swagger.api;

@Entity()
class GHErrorHints {
  
  @Property(name: 'message')
  String message = null;
  
  GHErrorHints();

  @override
  String toString()  {
    return 'GHErrorHints[message=$message, ]';
  }
}

