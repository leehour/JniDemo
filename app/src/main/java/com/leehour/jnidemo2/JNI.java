package com.leehour.jnidemo2;

import android.content.Context;
import android.util.Log;
import android.widget.Toast;

/**
 * Created by leehour on 2016/10/13.
 */

public class JNI {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String encode(String s);
    public static native String decode(String s);
}
