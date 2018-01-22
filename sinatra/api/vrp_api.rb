require 'json'


MyApp.add_route('POST', '/api/1/vrp/optimize', {
  "resourcePath" => "/Vrp",
  "summary" => "Solves vehicle routing problems",
  "nickname" => "post_vrp", 
  "responseClass" => "JobId", 
  "endpoint" => "/vrp/optimize", 
  "notes" => "This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.",
  "parameters" => [
    {
      "name" => "key",
      "description" => "your API key",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "body",
      "description" => "Request object that contains the problem to be solved",
      "dataType" => "Request",
      "paramType" => "body",
    }
    ]}) do
  cross_origin
  # the guts live here

  {"message" => "yes, it worked"}.to_json
end

