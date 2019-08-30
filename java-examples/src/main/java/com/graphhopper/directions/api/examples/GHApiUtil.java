package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.ApiClient;

public class GHApiUtil {

    public static ApiClient createClient() {
        ApiClient client = new ApiClient().setDebugging(true);
        client.setApiKey(System.getProperty("graphhopper.key", ""));
        return client;
    }
}
