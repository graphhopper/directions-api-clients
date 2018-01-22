require 'json'


MyApp.add_route('GET', '/api/1/geocode', {
  "resourcePath" => "/Geocoding",
  "summary" => "Execute a Geocoding request",
  "nickname" => "geocode_get", 
  "responseClass" => "GeocodingResponse", 
  "endpoint" => "/geocode", 
  "notes" => "This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ ",
  "parameters" => [
    {
      "name" => "q",
      "description" => "If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon.",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "locale",
      "description" => "Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used.",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "limit",
      "description" => "Specify the maximum number of returned results",
      "dataType" => "int",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "reverse",
      "description" => "Set to true to do a reverse Geocoding request",
      "dataType" => "boolean",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "point",
      "description" => "The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "provider",
      "description" => "Can be either, default, nominatim, opencagedata",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "key",
      "description" => "Get your key at graphhopper.com",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    ]}) do
  cross_origin
  # the guts live here

  {"message" => "yes, it worked"}.to_json
end

