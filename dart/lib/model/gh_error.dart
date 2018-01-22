part of swagger.api;

@Entity()
class GHError {
  
  @Property(name: 'code')
  int code = null;
  

  @Property(name: 'message')
  String message = null;
  

  @Property(name: 'hints')
  List<GHErrorHints> hints = [];
  
  GHError();

  @override
  String toString()  {
    return 'GHError[code=$code, message=$message, hints=$hints, ]';
  }
}

