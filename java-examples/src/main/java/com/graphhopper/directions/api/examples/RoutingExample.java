package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.ApiException;
import com.graphhopper.directions.api.client.api.RoutingApi;
import com.graphhopper.directions.api.client.model.ResponseInstruction;
import com.graphhopper.directions.api.client.model.RouteResponse;
import com.graphhopper.directions.api.client.model.RouteResponsePath;

import java.util.Arrays;

/**
 * A simple example for querying the Routing API.
 */
public class RoutingExample {
    public static void main(String[] args) {
        new RoutingExample().start();
    }

    private void start() {
        RoutingApi routing = new RoutingApi();
        String key = System.getProperty("graphhopper.key", "");
        try {
            RouteResponse rsp = routing.routeGet(Arrays.asList("48.58467,11.57753", "48.572859,11.592464"), false, key,
                    "en", true, "car", true, true, Arrays.<String>asList(), false,
                    "fastest", null, null, null, null, null,
                    null, null, null, null, null);
            RouteResponsePath path = rsp.getPaths().get(0);
            ResponseInstruction instr = path.getInstructions().get(0);
            System.out.println(instr.getText());
        } catch (ApiException ex) {
            System.out.println(ex.getResponseBody());
            throw new RuntimeException(ex);
        }
    }
}
