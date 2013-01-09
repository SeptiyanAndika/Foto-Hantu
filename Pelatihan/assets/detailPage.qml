import bb.cascades 1.0
import WebImageView 1.0

Page {
    titleBar: TitleBar {
        title: "Detail Image"
        //  visibility: ChromeVisibility.Visible
    }
    Container {
        layout: StackLayout {
        }
        TextArea {
            id: title
            editable: false
        }
        Container {
            layout: DockLayout {
            }
            verticalAlignment: VerticalAlignment.Fill
            horizontalAlignment: HorizontalAlignment.Fill
            WebImageView {
                id: img
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
            }
            ProgressIndicator {
                id: loading
                value: img.loading
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                onValueChanged: {
                    if (value == 1) {
                        loading.visible = false;
                    }
                }
            }
        }
    }
    function setData(judul, gambar) {
        title.text = judul;
        img.url = gambar;
    }
}
